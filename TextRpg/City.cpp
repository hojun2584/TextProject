#include "City.h"



City::City(LandInfo land) : Tile(land)
{
}

City::City(int cost, int owner, string name, string type) : Tile(cost, owner,name, type)
{
}

void City::EnterPlayer()
{
}

string City::changeState()
{
	return string();
}

int City::GetOwner()
{
	return land.owner;
}
