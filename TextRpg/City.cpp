#include "City.h"



City::City(LandInfo land) : Tile(land)
{
}

City::City(int cost, int owner, string name, string type) : Tile(cost, owner,name, type)
{

}

void City::Init()
{
	land.cost = cost;
	land.owner = owner;
	land.name = name;
	land.type = type;
}

void City::EnterPlayer()
{
}


void City::SetOwner(int owner)
{
	land.owner = owner;
	
}

int City::GetOwner()
{
	return land.owner;
}


//buildType == 1 villa , 2 == build , 3 == hotel;
int City::BulidCost(int buildType)
{

	if(buildType == 1)
	{
		return (int) land.cost * 1.4;
	}
	else if (buildType == 2)
	{
		return (int)land.cost * 1.6;
	}
	else if (buildType == 3)
	{
		return (int)land.cost * 2.0;
	}
}
