#include "Surprise.h"

Surprise::Surprise(string name, string type)
{
	tileInfo.name = name;
	tileInfo.type = type;
	tileInfo.cost = -1;
}

void Surprise::EnterPlayer(Player player)
{
}

string Surprise::EnterPlayer(Player* player)
{
	onPlayers.push_back(*player);

	if(GetName() == "Ȳ�ݿ���")
	{
		return LuckyCard(player);
	}
	else if( GetName() == "���ڵ�" )
	{

		return "���ڵ�";
	}
	
}

string Surprise::LuckyCard(Player* player)
{

	int number = GetCard();

	if (number <= 2)
	{
		player->WithdrowMoney(20);

		return "����";
	}
	else if (2 < number && number <= 5)
	{
		player->playerState.eventInfo.push_back("���ε�");
		return "���ε�";
	}
	else if (number == 6)
	{
		player->playerState.eventInfo.push_back("�����");
		return "�����";
	}

}



int Surprise::GetCard()
{

	srand(time(0));

	return rand() % 6 + 1;
}


int Surprise::GetCard(int range)
{

	srand(time(0));

	return rand() % range + 1;
}




