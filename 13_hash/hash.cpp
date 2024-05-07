#include <iostream>
#include <functional>

int main(){

    std::string str = "Meet the new boss...";
    std::size_t str_hash = std::hash<std::string>{}(str);
    std::cout  << str_hash % 10 << '\n';
}