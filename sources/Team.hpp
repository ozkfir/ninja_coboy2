#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstring>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include <vector>
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
using namespace std;

#ifndef TEAM
#define TEAM
class Team{
    int size;
    Character* character[10];
    Character * leader;
private:

public:
    bool leader_alive();
//    bool kind_of_player();

//    void set_size(int i);
    int get_size()const;
    Character * get_character(int i);
    void set_leader();///bool
    Character * get_leader();
    virtual Character * get_close_player(Character * character);

    Team(Character * leader);
    void add(Character * player);
    virtual void attack(Team *team);
    virtual void print();
    int stillAlive();
~Team();
};
#endif








