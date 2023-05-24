//
// Created by oz on 07/04/23.
//
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Ninja.hpp"
#include "Character.hpp"

int Ninja::get_speed() {return speed;}
void  Ninja::move(Character *enemy){
    this->setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),this->speed));
}

void Ninja::slash(Character * enemy){
    if(!this->isAlive() || !enemy->isAlive()){throw runtime_error("");}
    if(this==enemy){throw runtime_error("");}///////////////////////&&? and in slash
    if(this->distance(enemy)<= 1 )
            enemy->hit(40);
}




Ninja::Ninja(string name,Point point,int h_p,int speed_,int kind):Character(name,point,h_p,kind),speed(speed_){}
//Ninja::~Ninja() {}


YoungNinja::YoungNinja(string name,Point point): Ninja(name,point,100,14,YNINJA_){}
//YoungNinja::~YoungNinja(){}



TrainedNinja::TrainedNinja(string name,Point point): Ninja(name,point,120,12,TNINJA_){}
//TrainedNinja::~TrainedNinja(){}


OldNinja::OldNinja(string name,Point point): Ninja(name,point,150,8,ONINJA_){}
//OldNinja::~OldNinja(){}

string YoungNinja::print(){return "YoungNinja "+getName()+" HP "+to_string(get_HP());}
string OldNinja::print(){return "OldNinja "+getName()+" HP "+to_string(get_HP());}
string TrainedNinja::print() {return "TrainedNinja "+getName()+" HP "+to_string(get_HP());}