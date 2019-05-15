#include <iostream>

using namespace std;

class RealNumber {
public:
    RealNumber(double d=0.0);

    double getD();

private:
    double d;
};

RealNumber::RealNumber(double _d) {
    d = _d;
}

double RealNumber::getD() {
    return d;
}

int main() {
    RealNumber r1 = 1;
    RealNumber r2;

    cout << r1.getD() << " " << r2.getD() << endl;
    return 0;
}