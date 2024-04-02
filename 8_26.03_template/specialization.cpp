#include <iostream>
#include <string>

template<class T>
T Min(T a, T b){
  return a>=b?b:a;
}

template<>
std::string Min<std::string>(std::string a, std::string b){
    auto m = a.length();
    auto n = b.length();
    return    m>=n?b:a;
}

int main()
{
  int a=2;
  int b=4;
  std::string x = "Hello";
  std::string y = "Hi";
  std::cout<< Min(a,b) << std::endl;// 2
  std::cout<< Min(x,y) << std::endl; // Hi
}