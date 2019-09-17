#include <iostream>

using namespace std;

// Default constructors typically have no parameters, but they can have parameters with default values
class Box1 {
public:
    // Box1() {};  // default constructor has no param
    Box1(int i=1): m_i(i) {};  // default constructor has params with default values

private:
    int m_i;
};

// If no constructors are declared in a class, the compiler provides an implicit inline default constructor
class Box2 {
public:
    int volume() {return width * height * length;};

private:
    int width;  // If you rely on an implicit default constructor, be sure to initialize members in the class definition
    int height;
    int length;

    int anotherMember{0};  // right thing to do
};

int main() {
    Box1 b1;

    Box2 b2;
    cout << "b2: " << b2.volume() << endl;  // since we didn't init the members, b2.volume() will return a random value

}