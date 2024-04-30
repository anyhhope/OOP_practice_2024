#include <iostream>
using namespace std;

class BadStyle {
public:
    BadStyle(int n) :m_number(n) {}

    void SetNumber(int num) { m_number = num; }

    int GetNumber() const {
        return m_number;
    }

    void display_number() const {
        cout << "Number is: " << m_number << endl;
    }

private:
    int m_number;
};

int main() {
    BadStyle obj(10);
    obj.display_number();
    obj.SetNumber(20);
    cout << "New number is: " << obj.GetNumber() << endl;
    return 0;
}
