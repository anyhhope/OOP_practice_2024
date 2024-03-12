#include <iostream>
#include <vector>
#include <memory>

class MyClass {
public:
    int value{0};
    int value2{0};

    MyClass(int i){
        this->value = i;
    }

    void* operator new(size_t size) {
        std::cout << "MyClass, allocated " << size << std::endl;
        return ::operator new(size);
    }

    void operator delete(void* ptr, size_t size) {
        std::cout << "MyClass, deallocated " << size << std::endl;
        ::operator delete(ptr, size);
    }

};

void normal_ptr(){
    std::vector<MyClass*> vector_ptr;
    vector_ptr.reserve(10);
    for(int i = 0; i < 10; ++i){
        MyClass* ptr = new MyClass(i);
        vector_ptr.push_back(ptr);
    }

    delete vector_ptr.back();
    vector_ptr.pop_back();


    for(int i = 0; i < 10; ++i){
        std::cout << vector_ptr[i]->value << std::endl;
    }
}

void smart_ptr(){
    std::cout << "-------------------Unique" << std::endl;
    std::vector<std::unique_ptr<MyClass>> vector_ptr;
    vector_ptr.reserve(10);
    for(int i = 0; i < 10; ++i){
        // vector_ptr.push_back(std::unique_ptr<MyClass>(new MyClass(i)));
        vector_ptr.push_back(std::make_unique<MyClass>(i));
    }

    // delete vector_ptr.back();
    vector_ptr.pop_back();


    for(int i = 0; i < 10; ++i){
        std::cout << vector_ptr[i]->value << std::endl;
    }
}


int main(){
    normal_ptr();
    smart_ptr();
}
