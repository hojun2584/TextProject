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

	//player ���� Ÿ�Ͽ� �����ϴ� �÷��̾ �ִ°�
	bool IsPlayer();
	string GetType();

	//player '����' (����) ���� ����
	virtual void EnterPlayer(Player user);
	virtual void OutPlayer(Player user);


};

