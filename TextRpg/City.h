#pragma once
#include <string>
#include "Tile.h"

using namespace std;

class City : public Tile
{
public:


	City(LandInfo land);
	City(int cost, int owner, string name, string type);
	

	void Init();

	//virtual
	void EnterPlayer();


	void SetOwner(int owner);
	int GetOwner();
	int BulidCost(int bulidType);


};

