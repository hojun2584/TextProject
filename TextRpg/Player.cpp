#include "Player.h"

void Player::DepositMoney(int money)
{
	playerState.money += money;
}

void Player::WithdrowMoney(int money)
{
	playerState.money -= money;
}





