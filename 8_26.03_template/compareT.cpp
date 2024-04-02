#include <iostream>

template<typename T>
int compare(const T& a, const T& b) {
    if (a < b)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}

int main() {
    std::cout << compare<int>(5, 10) << std::endl; 
    std::cout << compare(3.14, 2.71) << std::endl;
    std::cout << compare('a', 'b') << std::endl; 
    std::cout << compare(std::string("apple"), std::string("apple")) << std::endl;

    return 0;
}
