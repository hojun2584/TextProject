#include "City.h"


City::City(string name, string type, int cost) : Tile(name, type)
{

	Init(name,type,cost);
	
}




void City::Init(string name, string type = "City", int cost = 30, int owner = -1)
{
	townInfo = new CityInfo();
	townInfo->cost = cost;
	townInfo->tile->name = name;
	townInfo->tile->type = type;
}


void City::SetOwner(int owner)
{
}

int City::GetOwner()
{
	return 0;
}

int City::bulidCost(int bulidType)
{

	

	return 0;
}
