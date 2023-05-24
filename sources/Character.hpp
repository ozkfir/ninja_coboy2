#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "point.hpp"
using namespace std;
namespace ariel{}
#ifndef CHARACTER
#define CHARACTER
typedef enum  {COWBOY_ = 0, YNINJA_=1,TNINJA_=2,ONINJA_=3} Result;

class Character{
    Point p;
    int hit_point;
    string name;
    int kind;
    bool in_team;

public:
    void set_inteam();
    bool get_inteam();
    int get_HP();

    Character(string name_,Point point,int hit,int kind);

    bool isAlive();

   double distance(Character * player);

   void hit(int num);
    int getkind();

    string getName();

    Point getLocation();
    virtual string print()=0;
    void setLocation(Point point);

     virtual ~Character();


};
#endif
