#include "Player.h"

Player::Player(int money, string name)
{

	playerMoney = money;
	this->name = name;

}

bool Player::IsDead()
{

	if (playerMoney <= 0) {
		return true;
	}

	return false;
}

void Player::DepositMoney(int deposit)
{

	playerMoney += deposit;

}

void Player::WithdrawMoney(int withdraw)
{

	playerMoney -= withdraw;

}


void Player::ChangePosition(int diceValue)
{

	if(currentPosition + diceValue > 30)
	{
		currentPosition = currentPosition + diceValue - 30;
		return;
	}
	currentPosition = currentPosition + diceValue;
	
}

