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
static string GetUnitType(Length length);
static string UnitToSuffix(LengthUnit unit);
static string UnitToName(LengthUnit unit);
static Length ConverterToMeters(Length length);


int main() {
    PrintLength(ReadLength());
    cout << GetUnitType(ReadLength()) << endl;
    PrintLength(ConverterToMeters(ReadLength()));
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
    // cout << "Length[value=" << length.value << ", unit=" << length.unit << "]" << endl;
    string suffix = UnitToSuffix(length.unit);
    string unitName = UnitToName(length.unit);
    cout << length.value << suffix << " (" << length.value << " " << unitName << "s)" << endl;
}

static string UnitToSuffix(LengthUnit unit) {
    #define DEFINE_UNIT(unit_name, value, symbol, system) if (unit == eLengthUnit_##symbol) return #symbol;
    #include "units.h"
    #undef DEFINE_UNIT
}

static string UnitToName(LengthUnit unit) {
    #define DEFINE_UNIT(unit_name, value, symbol, system) if (unit == eLengthUnit_##symbol) return #unit_name;
    #include "units.h"
    #undef DEFINE_UNIT
}

static string GetUnitType(Length length) {
    #define DEFINE_UNIT(unit_name, value, symbol, system) if (length.unit == eLengthUnit_##symbol) return #system;
    #include "units.h"
    #undef DEFINE_UNIT
}

static Length ConverterToMeters(Length length) {
    struct Length result;
    #define DEFINE_UNIT(unit_name, absValue, symbol, system) \
        if (length.unit == eLengthUnit_##symbol) {\
            result = {length.value * absValue, eLengthUnit_m};\
            return result;\
        }
    #include "units.h"
    #undef DEFINE_UNIT
}
