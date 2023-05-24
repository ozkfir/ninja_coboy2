#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include "Team.hpp"
using namespace std;

#ifndef TEAM2
#define TEAM2
class Team2:public Team{

private:
public:
    Team2(Character *obj);
    void attack(Team *team);
    void print();
    Character * get_close_player(Character * character);

};
#endif




#ifndef SMART_TEAM
#define SMART_TEAM
class SmartTeam:public Team{

public:
    Character * get_close_player(Character * character);

    SmartTeam(Character * obj);

    void attack(Team *team);
    void print();
};
#endif



