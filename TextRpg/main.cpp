#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include "PrintInfo.h"

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

	//City* city = dynamic_cast<City*>(tile);

	//if (city) {
	//	// city is a valid pointer to a City object
	//	city->someFunction();
	//}
	//else {
	//	// tile does not actually point to a City object
	//}

	City* city = new City(10, "20", "30");
	
	Tile* tile = city;


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

				result.push_back(new Tile(cost,name,type));
				if(type == "City")
				{
					//result.push_back(new City(10,"",""));
				}
				else if( type == "event" )
				{
					//TODO_List event class 구현
					//result.push_back(new Luck?());
				}
				else if ( type == "travel") {

					//TODO_LIST travel class 구현
					//result.push_back(new Travel() );
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
	string filename = "city.csv";
	PrintInfo printManager;
	vector<Tile*> landList;
	Player* myPlayer;
	int maxPlayers;
	int temp;
	int position;
	int dice;

	vector<Player*> players;
	vector<Player*>::iterator currentPlayers;
	
	landList = GetFileData(filename);

	
	printManager.InitActivity();
	printManager.IntroActivity();
	
	cin >> maxPlayers;

	// 입력 받은 수 만큼 플레이어 추가 및 첫번째 타일에 배치
	for(int i = 0 ; i < maxPlayers ; i++)
	{
		myPlayer = new Player( to_string(i+1) );
		players.push_back( myPlayer );
		(* landList.begin() )->EnterPlayer(*myPlayer);
	}
	
	currentPlayers = players.begin();

	while (true)
	{	
		printManager.LandActivity( players , landList);
		printManager.PrintPlayerInfo( *(*currentPlayers) );
		printManager.PrintDice(*(*currentPlayers));
		cin >> temp;

		dice = RollDiCE();
		cout << dice;
		cin >> temp;

		position = (*currentPlayers)->GetPosition() + dice;
		if( position < landList.size() )
		{
			(landList[(*currentPlayers)->GetPosition()])->OutPlayer( *(*(currentPlayers)) );
			(landList[position])->EnterPlayer( *(*currentPlayers) );
			(*(currentPlayers))->SetPosition(position);
		}
		else
		{
			position -= landList.size();
			(landList[(*currentPlayers)->GetPosition()])->OutPlayer(*(*(currentPlayers)));
			(landList[position])->EnterPlayer(*(*currentPlayers));
			(*(currentPlayers))->SetPosition(position);
		}
		if((landList[position])->getType() == "City")
		{
			
		}
		


		NextPlayer(players,currentPlayers);
	}

}