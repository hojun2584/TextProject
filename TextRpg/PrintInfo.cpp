#include "PrintInfo.h"
using namespace std;



void PrintInfo::InitActivity()
{
	

	system("mode con cols=120 lines=60 | title 창 제목");
	


}



void PrintInfo::IntroActivity()
{
	system("cls");
	gotoxy(50, 30);
	cout << "blue marble";

}


void PrintInfo::LandActivity(std::vector<Player> players, std::vector<City> citys)
{
	system("cls");

	int startX = 0;
	int startY = 52;




	PrintLand(startX, startY, citys.back());


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




void PrintInfo::PrintLand(int x, int y, City capital) {

	SetPrintInfo(capital);

	for (int i = 0; i <land.size() ; i++) 
	{
		gotoxy(x, y+i);
		cout << land[i];
	}

}

	

void PrintInfo::SetPrintInfo(City capital)
{
	
	string player = "  ";
	land.clear();


	land.push_back("|--------|");
	land.push_back("   " + capital.land->name);
	land.push_back("|--------|");
	land.push_back("|  owner |");
	

	// 물이 주인을 만나니 그 얼굴을 붉히더라.
	// 땅에 주인이 -1 == 아무도 가지지 않음을 의미 함 그게 아니라면
	// 값을 꺼내와서 출력 하라는 것
	if(capital.GetOwner() != -1)
	{
		land.push_back(to_string( capital.GetOwner() ) );
	}
	else 
	{
		land.push_back("|        |");
	}
	if(capital.land->type != "start")
	{
		land.push_back("    " + to_string(capital.land->cost));

	}
	else
	{
		land.push_back("|        |");
	}
	
	// 이 땅에 플레이어가 '현재' 기준으로 있는지 없는지 가시적으로 보여주기 위함
	// 현재 땅에 대한 어떤 플레이어가 존재하는 지는 tile클래스 내의 players가 저장하고 있음
	
	if(!capital.players.empty())
	{
		for(int i = 0 ; i < capital.players.size() ; i++)
		{
			player.append(capital.players[i].name);
			player.append(" ");
		}
		land.push_back(player);
	
	}
	else
	{
		land.push_back("|        |");
	}

	land.push_back("|--------|");


}
