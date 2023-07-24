#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include "PrintInfo.h"
#include "Surprise.h"
#include "Travel.h"
using namespace std;


vector<Tile*> GetFileData(string fileName)
{
	
	ifstream file(fileName);
	vector<vector<string>> data;
	vector<Tile*> result;
	vector<string> row;
	string value;
	string line;
	string name;
	string type;
	int count;
	int cost = 0;

	


	while (getline(file, line)) {
		row.clear();
		value.clear();
		stringstream ss(line);
		count = 0;
		while (getline(ss, value, ',')) {
			if(count == 0 )
			{	
				cost = stoi(value);
			}
			else if(count == 2 )
			{
				name = value;

			}
			else if(count == 3 )
			{
				type = value;
				count = 0;


				if(type == "city")
				{
					result.push_back(new City(cost, name, type));
				}
				else if( type == "event" )
				{
					//TODO_List event class 구현
					result.push_back(new Surprise(name,type));
				}
				else if ( type == "travel") {

					//TODO_LIST travel class 구현
					result.push_back(new Travel( { cost,name,type } ));
				}


				continue;
			}
			count++;
		}

		
	}

	return result;
}
 

int RollDiCE() {

	srand(time(0));
	return rand() % 6 + 1;
	
}

void NextPlayer(vector<Player*> &players , vector<Player*>::iterator &currentPlayers) {

	if (currentPlayers + 1 != players.end())
	{
		currentPlayers++;
	}
	else {
		currentPlayers = players.begin();
	}
};



int main()
{
	vector<Player*>::iterator currentPlayers;
	vector<Player*> players;
	vector<Tile*> landList;

	City* cityPointer;
	Travel* travelPointer;
	Surprise* surPointer;


	Player* myPlayer;

	PrintInfo printManager;
	
	string filename = "city.csv";
	string temp2;
	int maxPlayers;
	int position;
	int temp;
	int dice;
	
	landList = GetFileData(filename);

	printManager.InitActivity();
	printManager.IntroActivity();
	
	while(true)
	{
		printManager.gotoxy(90,33);
		cout << "플레이 하실 인원을 입력해 주세요 ( 2 ~ 4 ) ";
		cin >> maxPlayers;

		if(cin.good())
		{
			break;
		}
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(10,'\n');
		
		}
	
	}


	// 입력 받은 수 만큼 플레이어 추가 및 첫번째 타일에 배치
	for(int i = 0 ; i < maxPlayers ; i++)
	{

		myPlayer = new Player( to_string(i+1) );
		players.push_back( myPlayer );
		(*landList.begin())->EnterPlayer(*myPlayer);

	}
	
	currentPlayers = players.begin();
	
	
	
	while (true)
	{
		printManager.LandActivity(players, landList);
		printManager.PrintPlayerInfo(*(*currentPlayers));
		printManager.PrintDiceTemplate();

		cin >> temp2;

		dice = RollDiCE();
		printManager.PrintDice(dice);
		position = (*currentPlayers)->GetPosition() + dice;

		if (position < landList.size())
		{
			(landList[(*currentPlayers)->GetPosition()])->OutPlayer(*(*(currentPlayers)));
			(landList[position])->EnterPlayer(*(*currentPlayers));
			(*(currentPlayers))->SetPosition(position);
		}
		else
		{
			position -= landList.size();
			(landList[(*currentPlayers)->GetPosition()])->OutPlayer(*(*(currentPlayers)));
			(landList[position])->EnterPlayer(*(*currentPlayers));
			(*(currentPlayers))->SetPosition(position);
		}
		printManager.LandActivity(players, landList);


		// 플레이어가 방문한 땅이 주인이 없는 경우
		

		if (landList[position]->GetType() == "city")
		{
			cityPointer = dynamic_cast<City*>(landList[position]);

			if ( cityPointer->GetOwner() == nullptr)
			{

				if (cityPointer->IsBuild(*(*currentPlayers)))
				{

					while (true)
					{

						printManager.BuildTemplate(cityPointer, *(*currentPlayers));
						cin >> temp;

						if (cin.good())
						{
							if(!(cityPointer->GetBuilding() < temp && temp < 4))
							{
								continue;
							}

							break;
						}
						else if (cin.fail())
						{
							cin.clear();
							cin.ignore(10, '\n');

						}

					}


					if (temp != -1)
					{
						cityPointer->BuyCity(*currentPlayers, temp);
					}

				}
			}
			else
			{

				if (cityPointer->GetOwner() != (*currentPlayers))
				{

					cityPointer->VisitAnother( (*currentPlayers) );

					if(cityPointer->GetBuilding() != 3)
					{
						printManager.BuildTemplate(cityPointer, *(*currentPlayers));
						cin >> temp;

					}

				}


			}
		}

		if( landList[position]->GetType() == "travel")
		{
			travelPointer = dynamic_cast<Travel*>(landList[position]);

			(landList[(*currentPlayers)->GetPosition()])->OutPlayer(*(*(currentPlayers)));
			travelPointer->EnterPlayer( (*currentPlayers) , 20);
			(*(currentPlayers))->SetPosition( position );

		}

		if (landList[position]->GetType() == "event") 
		{
			surPointer = dynamic_cast<Surprise*>( landList[position] );

			string eventName = surPointer->EnterPlayer( *currentPlayers );

			if(eventName == "콩코드")
			{
				cout << "어디로 움직이실 건 가요?";
				cin >> position;
				(landList[(*currentPlayers)->GetPosition()])->OutPlayer( *(*(currentPlayers)) );
				(landList[position])->EnterPlayer( *(*currentPlayers) );
				(*(currentPlayers))->SetPosition(position);
			}
			if(eventName == "황금 열쇠")
			{
				surPointer->LuckyCard(*(currentPlayers));
			}
			
		}

		if ( (*currentPlayers)->GetMoney() < 0 )
		{
			(landList[(*currentPlayers)->GetPosition()])->OutPlayer(*(*(currentPlayers)));
			delete landList[(*currentPlayers)->GetPosition()];
			players.erase(currentPlayers);
			maxPlayers--;
		}

		if (players.size() == 1)
		{
			
			break;
		}
	
		NextPlayer(players,currentPlayers);
	}

	printManager.EndGameActivity( players.back() );

}