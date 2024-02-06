#ifndef CIRCLE_H
#define CIRCLE_H

#include "constants.hpp"

class Circle{
public:
    Circle() = default;
    Circle(double newX, double newY, double newRadius);
    double length();

private:
    double x{0.0};
    double y{0.0};
    double radius{1.0};
};

#endif