#include "circle.hpp"

Circle::Circle(double newX, double newY, double newRadius){
    x = newX;
    y = newY;
    radius = newRadius;
}

double Circle::length(){
    return 2 * PI * radius;
}