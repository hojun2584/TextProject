#include "PrintInfo.h"
using namespace std;



void PrintInfo::InitActivity()
{
	

	system("mode con cols=120 lines=60 | title â ����");
	


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
	

	// ���� ������ ������ �� ���� ��������.
	// ���� ������ -1 == �ƹ��� ������ ������ �ǹ� �� �װ� �ƴ϶��
	// ���� �����ͼ� ��� �϶�� ��
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
	
	// �� ���� �÷��̾ '����' �������� �ִ��� ������ ���������� �����ֱ� ����
	// ���� ���� ���� � �÷��̾ �����ϴ� ���� tileŬ���� ���� players�� �����ϰ� ����
	
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
