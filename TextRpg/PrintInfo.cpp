#include "PrintInfo.h"
using namespace std;



void PrintInfo::PositionInit()
{
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
	

	system("mode con cols=120 lines=60 | title Ã¢ Á¦¸ñ");
	


}



void PrintInfo::IntroActivity()
{
	system("cls");
	gotoxy(50, 30);
	cout << "blue marble";

}


void PrintInfo::LandActivity(std::vector<Player*> players, std::vector<Tile> tiles)
{
	system("cls");
	int tileCol = 10;
	int tileHeight = 10;
	
	

	for(int i = 0 ; i < 10 ; i++)
	{
		startX += tileCol;
		PrintLand(startX, startY, *(tiles.begin() + i));
	}

	for (int i = 10; i < 20; i++)
	{
		PrintLand(startX, startY-((i-10)*7), *(tiles.begin() + i));

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


	

void PrintInfo::SetPrintInfo(Tile currentTile)
{
	
	string text = "  ";
	vector<Player> players = currentTile.onPlayers;
	Player* owner = currentTile.tileInfo.owner ;

	land.clear();
	land.push_back("|--------|");
	land.push_back("| "+currentTile.tileInfo.name);
	land.push_back("|--------|");
	
	if( owner != nullptr)
	{
		land.push_back("| " + owner->playerState.name );
	}
	else {
		land.push_back("|        |");
	}
	
	land.push_back("    " + to_string( currentTile.tileInfo.cost ));
	
	
	if( !players.empty() )
	{
		text = "| ";
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
