#include <iostream>
#include <string>
#include <vector>

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


// If any non-default constructors are declared, the compiler does not provide a default constructor:
class Box3 {
public:
    Box3(int w, int h, int l): w(w), h(h), l(l) {}

private:
    int w;
    int h;
    int l;
};


// If your class requires more complex initialization, then you need to implement a custom copy constructor. For example, if a class member is a pointer then you need to define a copy constructor to allocate new memory and copy the values from the other's pointed-to object. The compiler-generated copy constructor simply copies the pointer, so that the new pointer still points to the other's memory location
class Box4 {
public:
    Box4(Box4& box);  // Not recommand
    Box4(const Box4& box);
    Box4(volatile Box4& box);
    Box4(volatile const Box4& box);

    Box4(const Box4& box, int i = 1);  // Additional parameters OK if they have default values
};


// You can prevent your object from being copied by defining the copy constructor as deleted:
class Box5 {
public:
    Box5() {};
    Box5(Box5& box) = delete;
};


// Move Constructor
class Box6 {
public:
    Box6() {cout << "default" << endl;}
    Box6(int w, int h, int l): w(w), h(h), l(l) {
        cout << "int,int,int" << endl;
    }
    Box6(Box6& b) : w(b.w), h(b.h), l(b.l), contents(b.contents) {
        cout << "copy" << endl;
    }
    Box6(Box6&& b) : w(b.w), h(b.h), l(b.l) {
        contents = std::move(b.contents);
        cout << "move" << endl;
    }

private:
    int w{0};
    int h{0};
    int l{0};
    vector<string> contents;
};


int main() {
    Box1 b1();
    Box2 b2;
    // Box2 b2();// (only) *compiler-generated default constructor* with parentheses causes error
    cout << "b2: " << b2.volume() << endl;  // since we didn't init the members, b2.volume() will return a random value

    // Box3 box3;  // Error! No default constructor found!
    // Box3 box3s[3];  // Another result of no default constructor
    Box3 box3s[3] = {{1,2,3}, {4,5,6}, {7,8,9}};  // But this works

    Box5 b51;
    // Box5 b52(b51);  // Error! Attempting to reference a deleted function.

    Box6 b61();
    Box6 b62(1, 2, 3);
    Box6 b63(b62);

}