#pragma once
#include "Tile.h"
#include "Player.h"
#include <algorithm>

class City : Tile
{

	struct CityInfo
	{
		// building =     1 == 별장 , 2 == 호텔, 3 == 빌딩
		int building = -1;
		TileInfo tile;
		

		CityInfo();
		CityInfo(TileInfo tile) {
			
			this->tile = tile;
			this->building = -1;
		};
		
		
	};

public:

	CityInfo cityState = tileInfo;
	
	City(TileInfo tile);
	City(int cost, string name, string type);

	bool IsBuild(Player player);
	bool IsOwner();

	int BuyLand(Player player);
	int BuyBila(Player player);
	int BuyHotel(Player player);
	int BuyBuilding(Player player);


	int VisitCost();
	vector<Player> GetPlayers();
	Player* GetOwner();
	string GetName();
	int GetCost();


	void VisitAnother(Player player);
	Player AnotherPlayerBuy(Player player,int buildType);
	
	bool IsAnotherBuy(Player player);
	int SumBuildCost();

	void EnterPlayer(Player player);
	void OutPlayer();

};

