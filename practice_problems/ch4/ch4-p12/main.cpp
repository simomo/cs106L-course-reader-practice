#include <string>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

enum LengthUnit {
    #define DEFINE_UNIT(unit_name, value, symbol, system) eLengthUnit_##symbol,
    #include "units.h"
    #undef DEFINE_UNIT
    eLengthUnit_ERROR,
};

struct Length {
    double value;
    LengthUnit unit;
};

static LengthUnit SuffixStringToLengthUnit(string suffix);
static Length ReadLength(void);
static inline void PrintLength(Length length);


int main() {
    cout << SuffixStringToLengthUnit("aaaaa") << endl;

    PrintLength(ReadLength());
    return 0;
}

static LengthUnit SuffixStringToLengthUnit(string suffix) {
    #define DEFINE_UNIT(unit_name, value, symbol, system) if (suffix == #symbol) return eLengthUnit_##symbol;
    #include "units.h"
    #undef DEFINE_UNIT

    return eLengthUnit_ERROR;
}

static Length ReadLength() {
    cout << "Please enter a mount, like '5 cm': " << endl;

    string userInput;
    while(getline(cin, userInput)) {
        stringstream converter;
        double value;
        string suffix;
        string rest;
        LengthUnit unit;
        Length length;
        string errorMsg = "the input format is invalid, it must be like '5 cm'";

        converter << userInput;
        if ((converter >> value >> suffix) && ! (converter >> rest)) {
            // cout << "Good! value: " << value << ", suffix: " << suffix << endl;
            
            if ((unit = SuffixStringToLengthUnit(suffix)) != eLengthUnit_ERROR) {
                length.value = value;
                length.unit = unit;
                return length;
            } else {
                errorMsg = "the suffix is invalid";
            }
        }

        cout << "Please check your input, beacuse " << errorMsg << endl;
    }
}

static inline void PrintLength(Length length) {
    cout << "Length[value=" << length.value << ", unit=" << length.unit << "]" << endl;
}