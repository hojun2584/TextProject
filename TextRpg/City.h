#pragma once
#include <string>
#include "Tile.h"

using namespace std;

class City : public Tile
{
public:

	City(LandInfo land);
	City(int cost, int owner, string name, string type);
	

	void Init(int cost, int owner, string name, string type);

	//virtual
	void EnterPlayer();
	string changeState();

	void SetOwner(int owner);
	int GetOwner();
	int bulidCost(int bulidType);


};

