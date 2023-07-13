
#include <iostream>
#include "PrintInfo.h"

using namespace std;

int main()
{

    PrintInfo *activityManager = new PrintInfo();
    activityManager->InitActivity();
    activityManager->IntroActivity();
    
    int temp = NULL;
    cin >> temp;
    
    vector<Player> player;
    vector<City> citys;

    Player *cus = new Player();
    player.push_back(*cus);



    while(NULL !=temp)
    {
        activityManager->LandActivity(player,citys);
        cin >> temp;
    }
    
}

