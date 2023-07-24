#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "Player.h"
#include "City.h"

using namespace std;

class PrintInfo
{
private:

	int position[40][2];
	int cols = 160, lines = 60;

	vector<string> land;


public:
	
	

	void PositionInit();

	void InitActivity();
	void IntroActivity();
	
	void LandActivity(std::vector<Player*> players , std::vector<Tile*> tiles);
	void EndActivity(std::vector<Player> player);
	void PrintLand(int x, int y, Tile* Tile);
	void SetPrintInfo(Tile* tileInfo);
	void gotoxy(int x, int y);
	
	void BuildTemplate(City* tile, Player player);

	void PrintDiceTemplate();
	void PrintPlayerInfo(Player player);
	void PrintDice(int dice);
	void PrintPlayer(vector<Player*> player);

	void EndGameActivity(Player* player);

};

