#pragma once
#include <string>
#include <vector>

using namespace std;

class Player
{
private:
	


public:
	
	int playerMoney = 300;
	int currentPosition = 0;
	string name = "player";
	string state = "normal";
	


	Player(int money, string name);

	bool IsDead();
	void DepositMoney(int deposit);
	void WithdrawMoney(int withdraw);
	void ChangePosition(int diceValue);
	

};

