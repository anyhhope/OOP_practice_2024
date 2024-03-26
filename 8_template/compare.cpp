#include <iostream>

int compare(int a, int b) {
    if (a < b)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}

int compare(double a, double b) {
    if (a < b)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}

int compare(char a, char b) {
    if (a < b)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}

int compare(const std::string& a, const std::string& b) {
    if (a < b)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}

int main() {
    std::cout << compare(5, 10) << std::endl; 
    std::cout << compare(3.14, 2.71) << std::endl;
    std::cout << compare('a', 'b') << std::endl;
    std::cout << compare(std::string("apple"), std::string("apple")) << std::endl;
}
