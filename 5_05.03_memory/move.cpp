#include <iostream>

class MyClass
{
public:
    MyClass() = default;
    // Конструктор перемещения
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr; 
        std::cout << "Move";
    }

private:
    int* data{nullptr};
};



int main(){
    MyClass a;
    MyClass b(std::move(a));

}