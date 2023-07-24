#include "Tile.h"
#include "Player.h"

Tile::Tile()
{

}

Tile::Tile(int cost, string name, string type)
{

	tileInfo.cost = cost;
	tileInfo.name = name;
	tileInfo.type = type;

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


int Tile::BuyTile(Player& player)
{
	return 0;
}

void Tile::OutPlayer(Player player)
{

	auto iter = find(onPlayers.begin(), onPlayers.end(), player);
	if(iter != onPlayers.end() )
	{
		onPlayers.erase(iter);
	};

}

void Tile::EnterPlayer(Player player)
{
	onPlayers.push_back(player);
}


