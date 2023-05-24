#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#ifndef POINT
#define POINT
#include <string>

namespace ariel {}

    class Point {
        double x, y;

    public:

        double get_x();
        double get_y();
        void set_y(double num);
        void set_x(double num);

        Point(double xxxx, double yyy);
        Point(const Point & point);

        double distance(Point ppp2);

        void print() const;

        static Point moveTowards(Point point_a,Point point_b, double distance);
    };

#endif
