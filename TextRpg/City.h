#pragma once
#include <algorithm>
#include "Tile.h"
#include "Player.h"

class City : public Tile
{

	struct CityInfo
	{
		// building =     1 == ���� , 2 == ȣ��, 3 == ����
		int building = -1;
		TileInfo tile;

		CityInfo();
		CityInfo(TileInfo tile) {
			
			this->tile = tile;
			this->building = -1;
		};
		
		
	};

	int BuyTile(Player& player);
	int BuyBuilding();
	int BuyHotel();
	int BuyBila();

public:

	CityInfo cityState = tileInfo;
	
	City(TileInfo tile);
	City(int cost, string name, string type);


	int GetBuilding();
	void SetBuilding(int building);
	bool IsBuild(Player player);
	bool IsOwner();
	
	int VisitCost();
	vector<Player> GetPlayers();
	Player* GetOwner();
	string GetName();
	int GetCost();


	void VisitAnother(Player* player);
	Player AnotherPlayerBuy(Player player,int buildType);
	
	bool IsAnotherBuy(Player player);
	int SumBuildCost();

	void EnterPlayer(Player player);
	void OutPlayer();

	
	void BuyCity(Player* player, int target);
	void SetOwner(Player* player);

};

