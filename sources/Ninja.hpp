#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "point.hpp"
#include "Character.hpp"

using namespace std;


#ifndef NINGA
#define NINGA

class Ninja:public Character{
    int speed;
protected:
public:
    Ninja(string name,Point point,int h_p,int speed_,int kind);
    int get_speed();
    void  move(Character *enemy);

    void slash(Character *enemy);
//~Ninja();
};
#endif





