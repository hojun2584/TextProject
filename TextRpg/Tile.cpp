#include "Tile.h"


Tile::Tile()
{
}

Tile::Tile(LandInfo land)
{

	this->land = land;

}

Tile::Tile(int cost, int owner, string name, string type)
{

	land = { cost,owner,name,type };
}



void Tile::Init(string name, string type)
{

	land.name = name;
	land.type = type;
}

bool Tile::OnPlayer(Player player)
{

	
	if (players.empty())
		return false;
	
	return true;

}

string Tile::getType()
{
	return land.type;
}

void Tile::OutPlayer()
{

}
