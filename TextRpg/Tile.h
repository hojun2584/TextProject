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

	//player ���� ��� �� �ִ� ����, ���� �ִ� ����
	void OnPlayer();
	void NotInPlayer();

	string getType();

	//player '����' (����) ���� ����
	void OutPlayer();
	virtual void EnterPlayer() = 0;
	//player�� '����' ���� ���°� ���� ��

	virtual string changeState() = 0;
	



};

