#include "PrintInfo.h"
using namespace std;



void PrintInfo::InitActivity()
{
	

	system("mode con cols=200 lines=60 | title 창 제목");
	land.push_back("----------");
	land.push_back("|        |");
	land.push_back("|________|");
	land.push_back("|        |");
	land.push_back("|        |");
	land.push_back("|        |");
	land.push_back("|        |");
	land.push_back("----------");
}

void PrintInfo::IntroActivity()
{
	system("cls");
	gotoxy(100, 30);
	cout << "blue marble";

}


void PrintInfo::LandActivity(std::vector<Player> players, std::vector<City> citys)
{
	system("cls");
	PrintLand(0,0);
}


void PrintInfo::EndActivity(std::vector<Player> player)
{
}

void PrintInfo::gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}


void PrintInfo::PrintLand(int x, int y) {

	vector<string>::iterator iter = land.begin();
	iter = land.begin();
	
	
	for(int i = 0 ; i < 8; i++)
	{
		
		for(int j = 0 ; j < 10 ; j++)
		{
			gotoxy(x + (j * 12), y+i);
			cout << land[i];
		}
		

	}
}