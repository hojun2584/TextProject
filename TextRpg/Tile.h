#pragma once
#include "Player.h"
#include <string>
#include <vector>

using namespace std;

class Tile abstract
{


public:

	struct TileInfo
	{

		int cost ;
		Player *owner ;
		string name ;
		string type ;
		TileInfo() 
		{
			cost = 30;
			name = "NULL";
			type = "City";
			owner = nullptr; 
		};
		TileInfo(int cost, string name, string type)
		{
			this->cost = cost;
			this->owner = nullptr;
			this->name = name;
			this->type = type;
		};

	};
	
	vector<Player> onPlayers;

	Tile();
	Tile(int cost, string name, string type);


	//player 현재 들어 와 있는 상태, 나가 있는 상태
	bool IsOnPlayer(Player player);
	string getType();


	//player '지금' (들어온) 나간 상태
	virtual void OutPlayer() = 0;
	virtual void EnterPlayer(Player player) = 0;


};

