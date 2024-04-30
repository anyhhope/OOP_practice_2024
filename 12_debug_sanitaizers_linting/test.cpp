#include <iostream>

void func1(int x) {
    int y = x * 2;
    std::cout << "func1: " << y << std::endl;
}

int func2(int a, int b) {
    return a + b;
}

int main() {
    int num1 = 10;
    int num2 = 20;
    int result;

    func1(num1);
    result = func2(num1, num2);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
