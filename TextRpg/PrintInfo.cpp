#include "PrintInfo.h"
using namespace std;

#define		CHECK cout<<"check";

void PrintInfo::PositionInit()
{

	int startX = -8;
	int startY = 1;

	int tileCol = 9;
	int tileHeight = 11;
	for(int i = 0; i < 10; i++)
	{
		position[i][0] = startX + ( i * tileCol );
		position[i][1] = startY;
	}

	for(int i = 10; i < 20; i++)
	{
		position[i][0] = startX;
		position[i][1] = startY;
	}

}

void PrintInfo::InitActivity()
{
	system("mode con cols=180 lines=60 | title BLUE_MARBLE");
}

void PrintInfo::IntroActivity()
{
	system("cls");
	gotoxy(90, 30);
	cout << "blue marble";
}






void PrintInfo::LandActivity(std::vector<Player*> players, std::vector<Tile*> tiles)
{
	system("cls");
	int tileCol = 10;
	int tileHeight = 10;
	int startX = -8;
	int startY = 50;
	
	
	for(int i = 0 ; i < 17 ; i++)
	{
		startX += tileCol;
		PrintLand(startX, startY, tiles[i] );
	}

	for (int i = 17 ; i < 21; i++)
	{
		startY -= tileHeight;
		PrintLand(startX, startY, tiles[i]);
	}
	for (int i = 21; i < 37; i++)
	{
		startX -= tileCol;
		PrintLand(startX, startY, tiles[i]);
	}
	for (int i = 37; i < 40; i++)
	{
		startY += tileHeight;
		PrintLand(startX, startY, tiles[i]);
	}
	
	PrintPlayer(players);

}





void PrintInfo::EndActivity(std::vector<Player> player)
{


}

void PrintInfo::gotoxy(int x, int y)
{

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void PrintInfo::BuildTemplate(City* tile, Player player)
{
	int x = 25, y = 20;

	vector<string> temp;
	int sum = 0;

	temp.push_back("플레이어가 가지고 있는 돈 : " + to_string( player.GetMoney() ));


	if (tile->GetBuilding() < 0)
	{
		sum += tile->GetCost();
		temp.push_back("땅을 사기 위해 필요한 돈 : " + to_string( sum ) );
	}
	if (tile->GetBuilding() < 1)
	{
		sum += tile->GetCost() * 0.2;
		temp.push_back("빌라을 사기 위해 필요한 돈 : " + to_string( sum ) );
	}
	if (tile->GetBuilding() < 2)
	{
		sum += tile->GetCost() * 0.4;
		temp.push_back("별장을 사기 위해 필요한 돈 : " + to_string(sum) );
	}
	if(tile->GetBuilding() < 3 )
	{
		sum += tile->GetCost() * 0.6;
		temp.push_back("호텔을 사기 위해 필요한 돈 : " + to_string(sum) );
	}

	

	while (!temp.empty())
	{
		y += 2;
		gotoxy(x, y);
		cout << temp.back();
		temp.pop_back();
	}

	gotoxy(x, y+1);
	cout << "구매하실 건물을 선택해 주세요.";



}




void PrintInfo::PrintLand(int x, int y, Tile* capital) {

	SetPrintInfo(capital);
	for (int i = 0; i <land.size() ; i++) 
	{
		gotoxy(x, y+i);
		cout << land[i];
	}

}


	

void PrintInfo::SetPrintInfo(Tile* currentTile)
{
	
	string text = "  ";
	vector<Player> players = currentTile->onPlayers;
	Player* owner =nullptr;
	City* cityPointer = nullptr;

	land.clear();
	land.push_back("|--------|");
	land.push_back(" "+currentTile->tileInfo.name);
	land.push_back("|--------|");
	
	
	
	if (currentTile->GetType() == "city")
	{
		cityPointer = dynamic_cast<City*>(currentTile);;
		owner = cityPointer->GetOwner();
	}


	


	if (owner != nullptr)
	{
		land.push_back("|    " + owner->GetName() + "   |");

		if (currentTile->GetType() == "city")
		{


			land.push_back("|  건물  |");
			land.push_back("|    " + to_string(cityPointer->GetBuilding()) + "   |");


		}
		else
		{
			land.push_back("|        |");
			land.push_back("|        |");
		}


	}
	else {
		land.push_back("|        |");
		land.push_back("|        |");
		land.push_back("|        |");

	}





	if (currentTile->GetCost() != -1)
	{
		land.push_back("|   " + to_string(currentTile->tileInfo.cost) + "   |");
	}
	else
	{
		land.push_back("|        |");
	}

	if (!players.empty())
	{
		text = " ";
		for (int i = 0; i < players.size(); i++)
		{
			text.append(players[i].playerState.name);
			text.append(" ");
		}
		land.push_back(text);

	}
	else
	{
		land.push_back("|         |");
	}

	land.push_back("|--------|");


}

void PrintInfo::PrintDiceTemplate()
{
	int x = 25, y = 24;
	vector<string> playerInfo;
	gotoxy(x , y);
	cout << "주사위를 굴리시겠습니까?";
	gotoxy(x , y +1);


	

}

void PrintInfo::PrintPlayerInfo(Player player)
{
	
	int x = 25, y = 20;
	vector<string> playerInfo;

	playerInfo.push_back("현재 플레이어의 턴 : " + player.GetName() );
	playerInfo.push_back("현재 플레이어의 돈 : " + to_string(player.GetMoney()) );

	while( !playerInfo.empty() )
	{
		y += 1;
		gotoxy(x, y);
		cout << playerInfo.back();
		playerInfo.pop_back();
	}

}

void PrintInfo::PrintDice(int dice)
{
	gotoxy(cols / 2, lines / 1.5);
	cout << "현재 주사위 수치는 " << dice << " 입니다.";

}

void PrintInfo::PrintPlayer(vector<Player*> player)
{
	int x = 80;
	int y = 0;

	for(int i = 0 ;  i < player.size(); i++)
	{
		gotoxy(x, y);
		cout << (player[i])->GetName();
		gotoxy(x, y+1);
		cout << (player[i])->GetPosition();
		gotoxy(x, y + 2);
		cout << (player[i])->GetMoney();
		x -= 10;
	}
	

}

void PrintInfo::EndGameActivity(Player* player)
{
	system("cls");
	gotoxy(80, 30);
	cout << player->GetName() << "님이 승리 하였습니다." << endl;


}
