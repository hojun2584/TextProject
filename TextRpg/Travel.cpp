#include "Travel.h"


using namespace std;




Travel::Travel()
{
}

Travel::Travel(TileInfo tile)
	: Tile(tile.cost, tile.name, tile.type)
{
	travel.tile.cost = 20;

}

void Travel::EnterPlayer(Player player)
{
	onPlayers.push_back(player);
	player.WithdrowMoney(20);
}

void Travel::EnterPlayer(Player* player , int money)
{
	int tmep;
	onPlayers.push_back(*player);
	player->WithdrowMoney(20);

}


