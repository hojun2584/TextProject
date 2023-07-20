#include "Tile.h"


Tile::Tile()
{
}

Tile::Tile(int cost, string name, string type)
{



}

int Tile::GetCost()
{
	return tileInfo.cost;
}

string Tile::GetName()
{
	return tileInfo.name;
}

string Tile::GetType()
{
	return tileInfo.type;
}

Player* Tile::GetOwner()
{
	return tileInfo.owner;
}

void Tile::SetCost(int cost)
{
	tileInfo.cost = cost;
}

void Tile::SetName(string name)
{
	tileInfo.name = name;
}

void Tile::SetType(string type)
{

	tileInfo.type = type;
}

void Tile::SetOwner(Player* owner)
{
	tileInfo.owner = owner;
}





bool Tile::IsOnPlayer(Player player)
{
	if (onPlayers.empty())
		return false;
	
	return true;
}

string Tile::getType()
{
	return string();
}

void Tile::OutPlayer()
{
}

void Tile::EnterPlayer(Player player)
{
	onPlayers.push_back(player);

}


