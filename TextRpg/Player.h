#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Player
{

	struct PlayerInfo
	{
		vector<string> eventInfo;
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

	void DepositMoney(int money);
	void WithdrowMoney(int money);
	int GetPosition();
	void SetPosition(int position);
	
};

