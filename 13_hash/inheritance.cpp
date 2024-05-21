#include <iostream>

class IBase {
public:


    virtual void printToStream(std::ostream& os) const = 0;
};

std::ostream& operator<<(std::ostream& os, const IBase& obj) {
    obj.printToStream(os);
    return os;
}

class Derived : public IBase {
public:
    Derived(int value) : value(value) {}

    virtual void printToStream(std::ostream& os) const override {
        os << "Derived: " << value;
    }

private:
    int value;
};

int main() {
    Derived* basePtr = new Derived(42);
    std::cout << *basePtr << std::endl;
    delete basePtr;

    return 0;
}
