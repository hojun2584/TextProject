#pragma once
#include "Player.h"
#include "Tile.h"
#include <string>

class Travel : public Tile
{
	struct TravelInfo
	{


		TileInfo tile;

		TravelInfo() {};
		TravelInfo(TileInfo tile)
		{
			this->tile = tile;
		}

	};


public:

	TravelInfo travel = tileInfo;

	Travel();
	Travel(TileInfo tile);

	void EnterPlayer(Player player) override;
	void EnterPlayer(Player* player, int money);

};

