#include "LandInfo.h"

LandInfo::LandInfo()
{
}

LandInfo::LandInfo(int cost, int owner, string name, string type)
{

	this->cost = cost;
	this->owner = owner;
	this->name = name;
	this->type = type;

}
