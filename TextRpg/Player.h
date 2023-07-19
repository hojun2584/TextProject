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
		PlayerInfo() { name = "1", money = 300; };
		PlayerInfo(string name , int money)
		{
			this->name = name;
			this->money = money;
		};
	};

public:

	PlayerInfo playerState;
	
	void DepositMoney(int money);
	void WithdrowMoney(int money);


};

