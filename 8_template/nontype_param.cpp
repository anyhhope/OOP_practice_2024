#include <iostream>
#include <string>

template <int N>
void printNTimes(const std::string& str) {
    std::cout << N << " times: " << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << str << std::endl;
    }
}

template<typename T, T value>
T addToValue(T x) {
    return x + value;
}

int main() {
    printNTimes<5>("Hello");
    printNTimes<3>("World"); 

    int result1 = addToValue<int, 5>(10); 
    //double result2 = addToValue<double, 3.14>(2.0); //ошибка

    std::cout << "Result: " << result1 << std::endl; 
}