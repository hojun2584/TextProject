#include "Player.h"

Player::Player()
{
}

Player::Player(string name)
{

	playerState.name = name;

}

void Player::DepositMoney(int money)
{
	playerState.money += money;
}

void Player::WithdrowMoney(int money)
{
	playerState.money -= money;
}

int Player::GetPosition()
{
	return playerState.currentPosition;
}

void Player::SetPosition(int position)
{

	playerState.currentPosition = position;

}





