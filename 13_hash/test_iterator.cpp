#include <iostream>



class CustomClass {
public:

    CustomClass() {
        for(int i = 0; i < 5; i++){
            data[i] = i;
        }
    }


    int* data = new int[5];


    class Iterator{

        public:
            Iterator(int* ptr) 
            : ptr(ptr) {};
            
            Iterator& operator++() {
                ++ptr;
                return *this;
            }

            bool operator!=(const Iterator& other) const {
                return ptr != other.ptr;
            }

            int& operator*() const {
                return *ptr;
            }


        //Iterator& operator++() // непосредственно для итерации - переходу к след элементу
        //bool operator!=(const Iterator& other) const // в цикле чтобы итератор понимал когда нужно закончить
        // то есть итератор должен уметь быть сравнимым с самим собой
        //returnType operator*() const //разыменование - что должен возвращать итератор


        private:
            int* ptr;
    };

    Iterator begin(){
        return Iterator(data);
    }


    Iterator end(){
        return Iterator(data + 5);
    }


};

int main(){

    CustomClass myClass;

    // CustomClass::Iterator

    // for(int i = 0; i < 5; i++){
    //     std::cout << myClass.data[i] << " ";
    // }
    std::cout << "\n";


    for (const auto& el : myClass) {
        std::cout << el << " ";
    }

    std::cout << "\n";
}