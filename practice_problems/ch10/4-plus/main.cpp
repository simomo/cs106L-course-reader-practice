#include <iostream>

using namespace std;

class MyInt {
public:
    MyInt(int i);

    // MyInt& operator+=(int other);
    const MyInt operator+(MyInt other);
    int getI() const;

private:
    int i;
};

MyInt::MyInt(int i) : i(i) {}

const MyInt MyInt::operator+(MyInt other) {
    MyInt mi(i+other.getI());
    return mi;
}

int MyInt::getI() const {return i;}

int main() {
    MyInt m1(1);
    MyInt m2(2);
    MyInt m3 = m1 + m2;
    cout << m3.getI() << endl;
    return 0;
}