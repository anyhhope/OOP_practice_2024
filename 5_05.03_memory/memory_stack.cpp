#include <iostream>

int main(){
    int a = 0;
    std::cout << "A address " << &a << std::endl;

    a = 0;
    std::cout << "A address " << &a << std::endl;

    int b = 0;
    std::cout << "B address " << &b << std::endl;

    {
        int c = 0;
        std::cout << "C address " << &c << std::endl;
    }

    int d = 0;
    std::cout << "D address " << &d << std::endl;
}