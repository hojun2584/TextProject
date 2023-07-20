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

	int startX = -8;
	int startY = 52;
	int position[40][2];

	vector<string> land;


public:
	
	

	void PositionInit();

	void InitActivity();
	void IntroActivity();
	void LandActivity(std::vector<Player*> players , std::vector<Tile> tiles);
	void EndActivity(std::vector<Player> player);
	void gotoxy(int x, int y);
	void PrintLand(int x, int y,Tile Tile);
	void SetPrintInfo(Tile tileInfo);

};

