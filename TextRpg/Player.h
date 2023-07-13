#pragma once
#include <string>

using namespace std;

class Player
{
private:
	


public:
	
	bool IsDead();
	void DepositMoney(int deposit);
	void WithdrawMoney(int withdraw);
	void ChangeState(string state);

	string name  = "player";
	int playerMoney = 300;
	string state = "normal";

};

