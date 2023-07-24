#pragma once
#include "Tile.h"
#include "Player.h"
class Surprise : public Tile
{


public:


	Surprise(string name , string type);
	void EnterPlayer(Player player) override;
	string EnterPlayer(Player* player);
	string LuckyCard(Player* player);
	void Concord(Player* player, int position);

	int GetCard();

	int GetCard(int range);

	

};

