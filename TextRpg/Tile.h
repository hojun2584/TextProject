#pragma once
#include "Player.h"
#include <string>
#include <list>

using namespace std;

class Tile
{

public:

	struct TileInfo
	{
		string name;
		string type;

	};

	TileInfo* tile;
	list<Player> *inPlayer;


	Tile();
	Tile(string name, string type);
	~Tile();

	//player 현재 타일에 존재하는 플레이어가 있는가
	bool IsPlayer();
	string GetType();

	//player '지금' (들어온) 나간 상태
	virtual void EnterPlayer(Player user);
	virtual void OutPlayer(Player user);


};

