#include "strutils.hh"

#include <cctype>  // toupper, tolower
#include <sstream>  // stringstream
#include <iostream>

using namespace std;

string ConvertToUpperCase(string input) {
    for (size_t i = 0; i < input.size(); ++i) {
        input[i] = toupper(input[i]);
    }

    return input;
}

string ConvertToLowerCase(string input) {
    for (size_t i = 0; i < input.size(); ++i) {
        input[i] = tolower(input[i]);
        cout << input[i] << endl;
    }

    cout << input << endl;
    return input;
}

/*
 * The book's way
 */
string IntegerToString(int value) {
    stringstream converter;
    converter << value;
    return converter.str();
}

/*
 * My original way :P
 */
string DoubleToString(double value) {
    string ret;

    stringstream converter;
    converter << value;
    converter >> ret;

    return ret;
}