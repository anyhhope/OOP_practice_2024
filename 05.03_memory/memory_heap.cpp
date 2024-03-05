#include <iostream>

class Heart{
public:
    Heart(){
        std::cout << "Constructor" << std::endl;
    }

    ~Heart(){
        std::cout << "Destructor" << std::endl;
    }

    void foo(){
        int j = 0;
        std::cout << "Function" << std::endl;
    }

private:
    int x{0};
    int y{0};
    int z{0};
};


int main(){
    Heart* pointer = new Heart();

    // double* pointer = new double(10);

    std::cout << "Size of pointer: " << sizeof(pointer) << std::endl; 
    std::cout << "Address of pointer: " << &pointer << std::endl; 
    std::cout << "Value of pointer: " << pointer << std::endl; 

    std::cout << "Size of value: " << sizeof(*pointer) << std::endl; 
    std::cout << "Address of value: " << &(*pointer) << std::endl; 
    // std::cout << "Value of value: " << *pointer << std::endl; 

    delete pointer;
}