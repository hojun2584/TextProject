#pragma once
#include <string>
#include "Tile.h"

using namespace std;

class City : Tile
{
public:
	City();
	City(string name, int havePlayer, int cost,string state);

	struct CityInfo
	{
		
		int owner;
		int cost;
		
	};

	CityInfo *city;
	
	void Init(string name, string state,int owner, int cost);

	void EnterPlayer();
	string changeState();

	void SetOwner(int owner);
	int GetOwner();
	int bulidCost(int bulidType);


};

