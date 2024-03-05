#include <iostream>

void memory_leak(){
    int* p = new int[10000];
    // delete;
    return;
}

void usage_after_delete(){
    int i = 10;
    int* p = new int;
    *p = 42;
    std::cout << *p << std::endl;
    std::cout << &p << std::endl;
    delete p;
    p = nullptr;
    std::cout << &p << std::endl;
    std::cout << p << std::endl;
    //не можем получить знаение после зануления указателя
    std::cout << *p << std::endl;
}

int main(){
    memory_leak();
    usage_after_delete();

}