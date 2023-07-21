#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "City.h"

using namespace std;


class Player
{

	struct PlayerInfo
	{
		vector<string> eventInfo;
		vector<Tile*> haveLand;
		string name;
		int money;
		int currentPosition = 0;

		PlayerInfo() { name = "1", money = 300; };
		PlayerInfo(string name , int money)
		{
			this->name = name;
			this->money = money;
		};

	};

public:

	PlayerInfo playerState;
	

	bool operator==(const Player& other) const
	{
		return playerState.name == other.playerState.name;
	}

	bool operator!=(const Player& other) const
	{
		return playerState.name != other.playerState.name;
	}

	Player();
	Player(string name);

	string GetName();
	int GetMoney();
	
	void SellTile();
	
	void DepositMoney(int money);
	void WithdrowMoney(int money);
	int GetPosition();
	void SetPosition(int position);
};

