#include "Tile.h"


Tile::Tile()
{
}

Tile::Tile(string name, string type)
{
	tile = new TileInfo();
	inPlayer = new list<Player>;
	tile->name = name;
	tile->type = type;

}


Tile::~Tile()
{
	delete inPlayer;
	delete tile;
}


bool Tile::IsPlayer()
{

	if(inPlayer->empty())
	{
		return false;
	}

	return true;
}

string Tile::GetType()
{
	return tile->type;
}


void Tile::EnterPlayer(Player user)
{

	inPlayer->push_back(user);
}

void Tile::OutPlayer(Player user)
{
	if(inPlayer->empty())
	{
		return;
	}
	else 
	{
		list<Player>::iterator iter = inPlayer->begin();
		for(int i = 0; i < inPlayer->size() ; i++)
		{
			if(iter->name == user.name)
			{
				inPlayer->erase(iter);
			}
		}
	}
}
