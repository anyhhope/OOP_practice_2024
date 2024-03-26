#include <iostream>
#include <string>

template<typename T1, typename T2>
struct Pair {
    T1 first;
    T2 second;

    Pair(const T1& f, const T2& s) : first(f), second(s) {}
};

template<typename T1, typename T2>
Pair<T1, T2> make_my_pair(const T1& first, const T2& second) {
    return Pair<T1, T2>(first, second);
}

int main() {
    Pair<int, double> myPair(5, 3.14);
    std::cout << "Pair 1: " << myPair.first << ", " << myPair.second << std::endl;

    std::string str = "my string";
    Pair<std::string, int> anotherPair = make_my_pair(str, 7);
    std::cout << "Pair 2: " << anotherPair.first << ", " << anotherPair.second << std::endl;

    return 0;
}
