#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include "Ninja.hpp"
#include "point.hpp"
#include "Character.hpp"
using namespace std;







#ifndef OLDNINGA
#define OLDNINGA
class OldNinja:public Ninja{
public:
    OldNinja(string name,Point point);
    string print();
//    ~OldNinja();
};
#endif
