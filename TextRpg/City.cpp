#include "City.h"




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

int City::BuyLand(Player player)
{
	cityState.tile.owner = &player;
	cityState.building = 0;
	return (int)(cityState.tile.cost);
}

int City::BuyBila(Player player)
{
	cityState.building = 1;
	return (int)(cityState.tile.cost*0.2);
}

int City::BuyHotel(Player player)
{
	cityState.building = 2;
	return (int)(cityState.tile.cost*0.4);
}

int City::BuyBuilding(Player player)
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



void City::VisitAnother(Player player)
{

	int money = VisitCost();

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


void City::EnterPlayer(Player player)
{
	onPlayers.push_back(player);
}

bool City::OutPlayer(Player player)
{
	
	if( onPlayers.empty() )
		
}

City::CityInfo::CityInfo()
{
}
