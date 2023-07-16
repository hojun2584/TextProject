#pragma once
#include <string>


using namespace std;

class LandInfo
{

public:

	int cost;
	int owner;
	string name;
	string type;




	LandInfo();
	LandInfo(int cost, int owner,string name, string type);

};

