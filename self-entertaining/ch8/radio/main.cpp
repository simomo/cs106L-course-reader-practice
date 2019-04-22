#include <map>
#include <cassert>
#include <iostream>

using namespace std;

class Radio {
public:
    Radio();
    Radio(double f, int v);

    double getFrequency();
    void setFrequency(double f);

    int getVolume();
    void setVolume(int v);

    double getPreset(int i);
    void setPreset(int i, double f);

private:
    double frequency;
    int volume;
    // map<int, double> preset;
    double preset[6];
};

Radio::Radio() {
    for (int i = 0; i < 6; ++i) {
        preset[i] = 0.0;
    }

    frequency = 87.5;
    volume = 5;
}

Radio::Radio(double f, int v) {
    for (int i = 0; i < 6; ++i) {
        preset[i] = 0.0;
    }

    frequency = f;
    volume = v;
}

double Radio::getFrequency() {
    return frequency;
}

void Radio::setFrequency(double f) {
    assert(f <= 108.0 && f >= 78.5);
    frequency = f;
}

int Radio::getVolume() {
    return volume;
}

void Radio::setVolume(int v) {
    assert(v <= 10 && v >= 0);
    volume = v;
}

double Radio::getPreset(int i) {
    assert(i <= 7 && i >= 1);
    assert(preset[i] != 0.0);
    return preset[i];
}

void Radio::setPreset(int i, double f) {
    assert(i <= 7 && i >= 1);
    assert(f <= 108.0 && f >= 78.5);
    preset[i] = f;
}

int main() {
    /* C++ will interpret this as “prototype a function called myRadio that takes in
no arguments and returns an FMRadio ” rather than “create an FMRadio called myRadio using the zero-
argument constructor.” This is sometimes referred to as “C++'s most vexing parse” and causes extremely
difficult to understand warnings and error messages. Thus, if you want to invoke the default constructor,
omit the parentheses. If you want to invoke a parametrized constructor, parenthesize the arguments. */
    Radio radio;  // 0-contructor is called
    Radio radio1();  // 0-contructor is NOT called. This is a function prototype

    Radio radio2(87.5, 5);

    cout << radio2.getVolume() << endl;
    return 0;
}