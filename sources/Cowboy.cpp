//
// Created by oz on 07/04/23.
//
#include "Cowboy.hpp"


Cowboy::Cowboy(string name_,Point point):Character(name_,point,110,COWBOY_),stack(6){
}

void Cowboy::shoot(Character * character){
    if(!this->isAlive() || !character->isAlive()){throw runtime_error("");}
    if(this==character){throw runtime_error("");}
    if (this->hasboolets()){
    character->hit(10);
    this->stack--;
    }
}

bool Cowboy::hasboolets(){
    return  stack>0;
}

void Cowboy::reload(){
    if(!this->isAlive()){throw runtime_error("");}
    stack=6;
}

string Cowboy::print() {return "cowboy "+getName()+" stack"+ to_string(stack)+" is alive"+((isAlive())?"true":"false")+" HP "+to_string(get_HP());}
//Cowboy::~Cowboy(){}