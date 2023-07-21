#include "City.h"




City::City(TileInfo tile) 
	: Tile(tile.cost ,tile.name , tile.type )
{
}

City::City(int cost, string name, string type)
{

	cityState.tile = { cost, name, type };

}

bool City::IsBuild(Player player)
{
	
	if(cityState.building !=3)
	{
		return true;
	}

	return false;
}

bool City::IsOwner()
{

	if (cityState.tile.owner == nullptr ) 
	{
		return false;
	}

	return true;
}

int City::BuyTile(Player &player)
{
	cityState.tile.owner = &player;
	cityState.building = 0;
	player.playerState.haveLand.push_back(this);

	return (int)(cityState.tile.cost);
}

int City::BuyBila(Player &player)
{
	cityState.building = 1;
	return (int)(cityState.tile.cost*0.2);
}

int City::BuyHotel(Player &player)
{
	cityState.building = 2;
	return (int)(cityState.tile.cost*0.4);
}

int City::BuyBuilding(Player &player)
{
	cityState.building = 3;
	return (int)(cityState.tile.cost*0.6);
}

int City::VisitCost()
{
	if(cityState.building == 1)
	{
		return (int)(cityState.tile.cost * 1.2);
	}
	else if (cityState.building == 2)
	{
		return (int)(cityState.tile.cost * 1.4);
	}
	else if (cityState.building == 3)
	{
		return (int)(cityState.tile.cost * 1.6);
	}
	else {

		return 0;
	}
}

vector<Player> City::GetPlayers()
{
	return onPlayers;
}




Player* City::GetOwner()
{

	return cityState.tile.owner;
}

int City::GetCost()
{
	return cityState.tile.cost;
}

string City::GetName()
{
	return cityState.tile.name;
}



void City::VisitAnother(Player player)
{

	int money = VisitCost();

	if(cityState.tile.owner == nullptr)
	{
		return;
	}

	if(player.playerState.money < money )
	{
		money = player.playerState.money;
		player.playerState.money = -1;
	}

	player.WithdrowMoney( money );

	if( !IsOwner() )
	{
		cityState.tile.owner->DepositMoney(money);
	
	}


}


Player City::AnotherPlayerBuy(Player player, int buildType)
{
	Player preOwner = *cityState.tile.owner;




	return preOwner;
}

bool City::IsAnotherBuy(Player player)
{
	if( (int)(SumBuildCost() * 1.2) <= player.playerState.money)
	{
		return true;
	}

	return false;
}

int City::SumBuildCost()
{

	if (cityState.building == 3) {

		return (int)(cityState.tile.cost * 1.6);
	}
	else if (cityState.building == 2)
	{
		return (int)(cityState.tile.cost * 1.4);
	}
	else if (cityState.building == 1)
	{
		return (int)(cityState.tile.cost * 1.2);
	}
	else {

		return cityState.tile.cost;
	}
}


void City::EnterPlayer(Player player)
{
	onPlayers.push_back(player);

	if( player != *GetOwner() )
	{
		VisitAnother(player);
		//값 처리 주인이 없을 때도 처리 했음
	}
}

void City::OutPlayer()
{
}


City::CityInfo::CityInfo()
{
}
