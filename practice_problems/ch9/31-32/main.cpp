#include <iostream>

using namespace std;

class RationalNumber
{
public:
    RationalNumber(int num = 0, int denom = 1) :
    numerator(num), denominator(denom) {}
    double getValue() const {
    return static_cast<double>(numerator) / denominator;
    }
    void setNumerator(int value) {
    numerator = value;
    }
    void setDenominator(int value) {
    denominator = value;
    }
private:
    int numerator, denominator;
};

class RealNumber {
public:
    RealNumber(double d=0.0);
    RealNumber(RationalNumber r);

    double getD();

private:
    double d;
};

RealNumber::RealNumber(double _d) {
    d = _d;
}

RealNumber::RealNumber(RationalNumber r) {
    d = r.getValue();
}

double RealNumber::getD() {
    return d;
}

int main() {
    RealNumber r1 = 1;
    RealNumber r2;

    RationalNumber ra1;
    RealNumber r3(ra1);
    RationalNumber ra2(1, 3);
    RealNumber r4 = ra2;

    cout << r1.getD()
         << " " << r2.getD()
         << " " << r3.getD()
         << " " << r4.getD() << endl;
    return 0;
}