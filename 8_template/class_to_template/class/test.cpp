#include "number.hpp"
#include <iostream>


int main(){
	Number intNum;   
    intNum.setNum(1);
    std::cout << "My integer + 1 is " << intNum.plus1() << "\n";
}