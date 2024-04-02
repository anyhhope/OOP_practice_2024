#include "number.hpp"
#include <iostream>


int main(){
	Number<double> intNum;   
    intNum.setNum(1);
    std::cout << "My double + 1 is " << intNum.plus1() << "\n";
}