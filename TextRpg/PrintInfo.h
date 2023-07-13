#pragma once


#include <Windows.h>
#include <iostream>
#include <vector>
#include "Player.h"
#include "City.h"



class PrintInfo
{
private:
	vector<string> land;

public:
	
	void InitActivity();
	void IntroActivity();
	void LandActivity(std::vector<Player> players , std::vector<City> citys);
	void EndActivity(std::vector<Player> player);
	void gotoxy(int x, int y);
	void PrintLand(int x, int y);
};

