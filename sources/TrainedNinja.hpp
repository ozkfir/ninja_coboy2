#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include "Ninja.hpp"
#include "point.hpp"
#include "Character.hpp"
using namespace std;



#ifndef TRAINEDNINGA
#define TRAINEDNINGA
class TrainedNinja:public Ninja{
public:
    TrainedNinja(string name,Point point);
    string print();
//    ~TrainedNinja();
};
#endif
