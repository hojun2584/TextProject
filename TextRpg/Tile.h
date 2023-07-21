#pragma once
#include <string>
#include <vector>
using namespace std;

class Player;



class Tile
{

public:

	struct TileInfo
	{

		int cost;
		Player* owner;
		string name;
		string type;
		TileInfo() 
		{
			cost = 30;
			name = "NULL";
			type = "City";
			owner = nullptr; 
		};
		TileInfo(int cost, string name, string type)
		{
			this->cost = cost;
			this->owner = nullptr;
			this->name = name;
			this->type = type;
		};

	};

	
	vector<Player> onPlayers;
	TileInfo tileInfo;

	Tile();
	Tile(int cost, string name, string type);



	int GetCost();
	string GetName();
	string GetType();
	Player* GetOwner();

	void SetCost(int cost);
	void SetName(string name);
	void SetType(string type);
	void SetOwner(Player* owner);

	//player ���� ��� �� �ִ� ����, ���� �ִ� ����
	bool IsOnPlayer(Player player);
	string getType();

	
	
	int BuyTile(Player& player);
	void OutPlayer(Player player);
	virtual void EnterPlayer(Player player);


};

