#pragma once
#include "Player.h"
#include <string>

using namespace std;

class Tile abstract
{

	struct TileInfo
	{
		string name;
		string type;
	};

	void Init(string name, string state);

	//player 현재 들어 와 있는 상태, 나가 있는 상태
	void OnPlayer();
	void NotInPlayer();

	string getType();

	//player '지금' (들어온) 나간 상태
	void OutPlayer();
	virtual void EnterPlayer() = 0;
	//player가 '지금' 들어와 상태가 변할 때

	virtual string changeState() = 0;
	



};

