#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include "PrintInfo.h"
#include "LandInfo.h"

using namespace std;


vector<LandInfo> GetFileData(string filePath)
{
	string filename = "city.csv";
	string content;
	string field;
	vector<string> fields;

	vector<LandInfo> result;

	ifstream file(filename);
	stringstream ss(content);


	if (!file) {
		ofstream outfile(filename);
		outfile.close();
	}
	else {
		content.assign((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));

	}

	while (getline(ss, field, ',')) {
		fields.push_back(field);
	}

	// Print the resulting fields
	for (const auto& f : fields) {
		
	}

	return result;

}

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
		
		//vector<Player> players, vector<City> citys
		printManager.LandActivity(players,citys);
		cin >> temp;


	}

	



	


}

