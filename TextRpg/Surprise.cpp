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

	if(GetName() == "황금열쇠")
	{
		return LuckyCard(player);
	}
	else if( GetName() == "콩코드" )
	{

		return "콩코드";
	}
	
}

string Surprise::LuckyCard(Player* player)
{

	int number = GetCard();

	if (number <= 2)
	{
		player->WithdrowMoney(20);

		return "벌금";
	}
	else if (2 < number && number <= 5)
	{
		player->playerState.eventInfo.push_back("무인도");
		return "무인도";
	}
	else if (number == 6)
	{
		player->playerState.eventInfo.push_back("통행료");
		return "통행료";
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




