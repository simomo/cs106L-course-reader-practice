#include <string>
#include <cmath>
#include <iostream>

using namespace std;

enum LengthUnit {
    #define DEFINE_UNIT(unit_name, value, symbol, system) eLengthUnit_##symbol,
    #include "units.h"
    #undef DEFINE_UNIT
    eLengthUnit_ERROR,
};

LengthUnit SuffixStringToLengthUnit(string suffix) {
    #define DEFINE_UNIT(unit_name, value, symbol, system) if (suffix == #symbol) return eLengthUnit_##symbol;
    #include "units.h"
    #undef DEFINE_UNIT

    return eLengthUnit_ERROR;
}

int main() {
    cout << SuffixStringToLengthUnit("aaaaa") << endl;
    return 0;
}

