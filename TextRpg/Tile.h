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
	//player ���� ��� �� �ִ� ����, ���� ��	�� ����
	bool OnPlayer(Player player);

	string getType();

	//player '����' (����) ���� ����
	void OutPlayer();
	virtual void EnterPlayer() = 0;


};

