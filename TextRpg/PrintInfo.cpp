#include "PrintInfo.h"
using namespace std;

#define		CHECK cout<<"check";

void PrintInfo::PositionInit()
{

	int startX = -8;
	int startY = 52;

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
	system("mode con cols=160 lines=60 | title BLUE_MARBLE");
}

void PrintInfo::IntroActivity()
{
	system("cls");
	gotoxy(50, 30);
	cout << "blue marble";
}



void PrintInfo::LandActivity(std::vector<Player*> players, std::vector<Tile*> tiles)
{
	system("cls");
	int tileCol = 10;
	int tileHeight = 7;
	int startX = -8;
	int startY = 52;
	
	
	for(int i = 0 ; i < 15 ; i++)
	{
		startX += tileCol;
		PrintLand(startX, startY, *tiles[i] );
	}

	for (int i = 15 ; i < 22; i++)
	{
		startY -= tileHeight;
		PrintLand(startX, startY, *tiles[i]);
	}
	for (int i = 19; i < 33; i++)
	{
		startX -= tileCol;
		PrintLand(startX, startY, *tiles[i]);
	}
	for (int i = 33; i < 39; i++)
	{
		startY += tileHeight;
		PrintLand(startX, startY, *tiles[i]);
	}
	

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




void PrintInfo::PrintLand(int x, int y, Tile capital) {

	SetPrintInfo(capital);
	for (int i = 0; i <land.size() ; i++) 
	{
		gotoxy(x, y+i);
		cout << land[i];
	}

}


	

void PrintInfo::SetPrintInfo(Tile &currentTile)
{
	
	string text = "  ";
	vector<Player> players = currentTile.onPlayers;
	Player* owner = currentTile.tileInfo.owner ;

	land.clear();
	land.push_back("|--------|");
	land.push_back(" "+currentTile.tileInfo.name);
	land.push_back("|--------|");
	
	if( owner != nullptr)
	{
		land.push_back("| " + owner->playerState.name );
	}
	else {
		land.push_back("|        |");
	}

	if(currentTile.GetCost() != -1)
	{
		land.push_back("    " + to_string(currentTile.tileInfo.cost));
	}
	else
	{
		land.push_back("|        |");
	}
	
	if( !players.empty() )
	{
		text = " ";
		for(int i = 0 ; i < players.size(); i++)
		{
			text.append(players[i].playerState.name);
			text.append(" ");
		}
		land.push_back(text);
	
	}
	else
	{
		land.push_back("|        |");
	}

	land.push_back("|--------|");


}

void PrintInfo::PrintDice(Player player)
{
	
	gotoxy(cols / 2, lines / 2);
	cout << "주사위를 굴리시겠습니까?";
	gotoxy(cols / 2, (lines / 2) +1);
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
