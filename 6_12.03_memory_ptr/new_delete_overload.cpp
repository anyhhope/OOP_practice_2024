#include <iostream>


void* operator new(size_t size) {
    std::cout << "New, allocated " << size << std::endl;
    return malloc(size);
}

void operator delete(void* ptr, size_t size) {
    std::cout << "Delete, deallocated " << size << std::endl;
    return free(ptr);
}

void* operator new[](size_t size) {
    std::cout << "New[], allocated " << size << std::endl;
    return malloc(size);
}

void operator delete[](void* ptr) noexcept {
    std::cout << "Delete[], deallocated " << std::endl;
    return free(ptr);
}

class MyClass {
public:
    int value{0};
    int value2{0};
    // void* operator new(size_t size) {
    //     std::cout << "MyClass, allocated " << size << std::endl;
    //     return malloc(size);
    // }

    // void operator delete(void* ptr, size_t size) {
    //     std::cout << "MyClass, deallocated " << size << std::endl;
    //     return free(ptr);

    void* operator new(size_t size) {
        std::cout << "MyClass, allocated " << size << std::endl;
        return ::operator new(size);
    }

    void operator delete(void* ptr, size_t size) {
        std::cout << "MyClass, deallocated " << size << std::endl;
        ::operator delete(ptr, size);
    }

};

int main(){
    // double* ptr = new double(25.0);
    // delete ptr;

    // double* ptr_arr = new double[5];
    // delete[] ptr_arr;

    MyClass* ptr_class = new MyClass;
    delete ptr_class;

}