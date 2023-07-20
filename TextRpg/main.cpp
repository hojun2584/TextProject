#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include "PrintInfo.h"

using namespace std;


vector<Tile> GetFileData(string fileName)
{
	
	ifstream file(fileName);
	vector<vector<string>> data;
	vector<Tile> result;
	vector<string> row;
	string value;
	Tile tile;
	int count;
	string line;
	while (getline(file, line)) {
		row.clear();
		value.clear();
		stringstream ss(line);
		count = 0;
		while (getline(ss, value, ',')) {
			if(count == 0 )
			{	
				tile.SetCost( stoi(value) );
			}
			else if(count == 2 )
			{
				tile.SetName(value);
			}
			else if(count == 3 )
			{
				tile.SetType(value);
				count = 0;
				continue;
			}
			count++;
		}
		result.push_back(tile);
	}

	


	return result;

}

int main()
{
	string filename = "city.csv";
	PrintInfo printManager;
	vector<Tile> landList;
	Player* myPlayer;

	int maxPlayers;


	vector<Player*> players;
	vector<Player*>::iterator currentPlayers = players.begin();
	
	landList = GetFileData(filename);

	

	printManager.InitActivity();
	printManager.IntroActivity();

	
	cin >> maxPlayers;
	
	for(int i = 0 ; i < maxPlayers ; i++)
	{
	
		myPlayer = new Player( to_string(i+1) );
		players.push_back( myPlayer );
		landList.begin()->onPlayers.push_back( *myPlayer );

	}

	int temp = 0;
	int phase = 0;


	while (true)
	{	
		printManager.LandActivity( players , landList);
		cin >> temp;

	}



}