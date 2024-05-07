#include <iostream>


struct Value {
    std::string category = "default";
};


class CustomClass {
public:

    CustomClass() {
        for(int i = 0; i < 5; i++){
            data[i] = i;
        }
    }


    int* data = new int[5];
    Value value;


    class Iterator{

        public:
            Iterator(CustomClass* customClass, size_t size, size_t index) 
            : customClass(customClass), size(size), index(index) {};
            
            Iterator& operator++() {
                ++index;
                return *this;
            }

            bool operator!=(const Iterator& other) const {
                return index != other.index;
            }

            std::string operator*() const {
                if (index < size){
                    return std::to_string(*(customClass->data + index));
                } else {
                    return customClass->value.category;
                }
            }


        //Iterator& operator++() // непосредственно для итерации - переходу к след элементу
        //bool operator!=(const Iterator& other) const // в цикле чтобы итератор понимал когда нужно закончить
        // то есть итератор должен уметь быть сравнимым с самим собой
        //returnType operator*() const //разыменование - что должен возвращать итератор


        private:
            // int* ptr;
            CustomClass* customClass;
            size_t size;
            size_t index;

    };

    Iterator begin(){
        return Iterator(this, 6, 0);
    }


    Iterator end(){
        return Iterator(this, 6, 6);
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