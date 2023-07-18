#pragma once
#include "Player.h"
#include "LandInfo.h"
#include <string>
#include <vector>

using namespace std;

class Tile abstract
{


public:

	LandInfo land;
	vector<Player> players;

	Tile();
	Tile(LandInfo land);
	Tile(int cost, int owner, string name, string type);




	void Init(string name, string type);
	//player 현재 들어 와 있는 상태, 나가 있	는 상태
	bool OnPlayer(Player player);

	string getType();

	//player '지금' (들어온) 나간 상태
	void OutPlayer();
	virtual void EnterPlayer() = 0;


};

