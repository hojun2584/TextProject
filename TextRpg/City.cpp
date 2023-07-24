#include "City.h"




City::City(TileInfo tile) 
	: Tile(tile.cost ,tile.name , tile.type )
{
}

City::City(int cost, string name, string type):Tile(cost,name,type)
{

}

int City::GetBuilding()
{
	return cityState.building;
}

void City::SetBuilding(int building)
{

	cityState.building = building;

}

bool City::IsBuild(Player player)
{
	
	if( cityState.building == -1 && player.GetMoney() >= GetCost() )
	{
		return true;
	}
	else if (cityState.building == 0 && player.GetMoney() >= GetCost()*0.2 )
	{
		return true;
	}
	else if (cityState.building == 1 && player.GetMoney() >= GetCost()*0.4 )
	{
		return true;
	}
	else if (cityState.building == 2 && player.GetMoney() >= GetCost() * 0.6)
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
	cityState.building = 0;
	player.playerState.haveLand.push_back(this);
	return (int)(cityState.tile.cost);
}

int City::BuyBila()
{

	
	cityState.building = 1;
	return (int)(cityState.tile.cost*0.2);
}

int City::BuyHotel()
{
	

	cityState.building = 2;
	return (int)(cityState.tile.cost*0.4);
}

int City::BuyBuilding()
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



void City::VisitAnother(Player* player)
{

	int money = VisitCost();

	if(cityState.tile.owner == nullptr)
	{
		return;
	}

	if(player->playerState.money < money )
	{
		money = player->playerState.money;
		player->playerState.money = -1;
	}
	else
	{
		player->WithdrowMoney(money);
	}

	
	if( IsOwner() )
	{

		this->cityState.tile.owner->DepositMoney(money);

	}
	
}


Player City::AnotherPlayerBuy(Player player, int buildType)
{
	Player preOwner = *cityState.tile.owner;

	int sum;


	for (int i = 0; i <= buildType; i++)
	{
		if (i == 0)
		{
			sum += GetCost();
		}
		else if (i == 1)
		{
			sum += GetCost()*0.2;
		}
		else if (i == 2)
		{
			sum += GetCost() * 0.4;
		}
		else if (i == 3)
		{
			sum += GetCost() * 0.6;
		}

	}

	sum *= 0.2;



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

	if( GetOwner() == nullptr)
	{
		return;
	}


}

void City::OutPlayer()
{
}



void City::BuyCity(Player* player, int target)
{

	int sum = 0;

	for(int i = GetBuilding() ; i <= target ; i++)
	{
		if(i == 0)
		{
			sum += BuyTile(*player);
		}
		else if( i == 1)
		{
			sum += BuyBila();
		}
		else if( i == 2)
		{
			sum += BuyBuilding();
		}
		else if( i == 3)
		{
			sum += BuyHotel();
		}

	}

	SetBuilding(target);
	SetOwner(player);
	player->WithdrowMoney(sum);

	


}

void City::SetOwner(Player* player)
{

	cityState.tile.owner = player;

}


City::CityInfo::CityInfo()
{
}
