#include "Player.h"

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

void Player::ChangeState(string state)
{

	this->state = state;
}
