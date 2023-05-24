#include <iostream>
#include "point.hpp"
#include <cmath>
using namespace std;

Point::Point(const Point & point){
    this->x=point.x;
    this->y=point.y;
}

double Point::get_x()
{
    return this->x;
}
double Point::get_y(){
    return y;
}
void Point::set_x(double x_)
{
    this->x=x_;
}
void Point::set_y(double y_){
    y=y_;
}
Point::Point(double x_,double y_):x(x_),y(y_){}

double Point::distance(Point p2){
    return ::sqrt((this->x-p2.x)*(this->x-p2.x)+(this->y-p2.y)*(this->y-p2.y));
}

void Point::print()const{
    cout<<"("<<x<<","<<y<<")"<<endl;
}

Point Point::moveTowards(Point a, Point b, double distance) {
    if (distance<0){throw invalid_argument("");}
   double distance_ab=a.distance(b);
   Point temp(1,1);
   if(distance_ab<distance) {
       temp.set_x( b.get_x());
       temp.set_y( b.get_y());
   }
   else{
       temp.set_x(((distance/distance_ab)*(b.get_x()-a.get_x()))+a.get_x());
       temp.set_y((((distance/(distance_ab))*(b.get_y()-a.get_y()))+a.get_y()));
   }
    return temp;
}