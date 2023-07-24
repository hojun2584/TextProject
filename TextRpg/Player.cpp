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

void Player::SellTile(Tile* tile)
{

	City *city = dynamic_cast<City*>( tile );

	auto iter = find(playerState.haveLand.begin(), playerState.haveLand.end(), tile);

	if( city->GetBuilding() == 0)
	{
		city->SetBuilding(-1);
		city->SetOwner(nullptr);
		DepositMoney( (int)(city->GetCost() * 0.8) );
		playerState.haveLand.erase(iter);
	}
	
}



void Player::DepositMoney(int money)
{
	playerState.money += money;
}

void Player::WithdrowMoney(int money)
{
	playerState.money = playerState.money - money;
}

int Player::GetPosition()
{
	return playerState.currentPosition;
}

void Player::SetPosition(int position)
{

	playerState.currentPosition = position;

}





