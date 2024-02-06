#include <iostream>

const double PI{3.14159265358};

class Circle{
public:
    Circle(){
        x = 1.0;
        y = 2.0;
        radius = 5.7;
    } //default

    Circle(double newX, double newY, double newRadius){
        x = newX;
        y = newY;
        radius = newRadius;
    }

    double length(){
        return 2 * PI * radius;
    }

private:
    double x{0.0};
    double y{0.0};
    double radius{1.0};
};



int main(){
    Circle circle1;
    std::cout << "Circumference 1: " << circle1.length() << std::endl;

    Circle circle2(4.0, -6.0, 1.5);
    std::cout << "Circumference 2: " << circle2.length() << std::endl;
}