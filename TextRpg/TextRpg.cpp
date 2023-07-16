#include <list>
#include <iostream>
#include "PrintInfo.h"
#include "LandInfo.h"

using namespace std;

int main()
{
	

	list<LandInfo> landList;
	PrintInfo printManager;
	
	int maxPlayers;
	vector<Player> players;
	vector<Player>::iterator currentPlayers = players.begin();
	vector<City> citys;

	City city = { 30,-1,"seoul","city" };

	city = { 30,-1,"seoul","city" };


	citys.push_back(city);




	printManager.InitActivity();
	printManager.IntroActivity();

	cin >> maxPlayers;



	int temp;



	while(true)
	{
		
		//std::vector<Player> players, std::vector<City> citys
		printManager.LandActivity(players,citys);
		cin >> temp;


	}

	



	


}

