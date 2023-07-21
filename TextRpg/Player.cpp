#include "Player.h"

Player::Player()
{
}

Player::Player(string name)
{

	playerState.name = name;

}

string Player::GetName()
{
	return playerState.name;
}

int Player::GetMoney()
{
	return playerState.money;
}

void Player::SellTile()
{
	//City* city = dynamic_cast<City*>(tile);

	//if (city) {
	//	// city is a valid pointer to a City object
	//	city->someFunction();
	//}
	//else {
	//	// tile does not actually point to a City object
	//}


	// TODO_LIST city class �ٿ� ĳ��Ʈ �� ��
	// ��ĳ��Ʈ �� �� owner �ʱ� ȭ �� have land���� �� erase()
	City *city = dynamic_cast<City*>( playerState.haveLand.back() );

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





