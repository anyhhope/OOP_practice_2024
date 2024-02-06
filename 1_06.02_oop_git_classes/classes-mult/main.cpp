#include <iostream>
#include "circle.hpp"
#include "constants.hpp"


int main(){
    Circle circle1;
    std::cout << "Circumference 1: " << circle1.length() << std::endl;

    std::cout << PI << std::endl;

    Circle circle2(4.0, -6.0, 1.5);
    std::cout << "Circumference 2: " << circle2.length() << std::endl;
}