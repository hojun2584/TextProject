#pragma once
#include <string>
#include "Tile.h"

using namespace std;

struct CityStruct
{
	int a;
};

class City : public Tile
{

public:
	struct CityInfo
	{
		TileInfo* tile;
		int owner;
		int cost;
	};

	CityInfo* townInfo;

	City();
	City(string name, string type, int cost);
	

	void Init(string name, string type, int cost, int owner);
	void SetOwner(int owner);
	int GetOwner();
	int bulidCost(int bulidType);
	
};

