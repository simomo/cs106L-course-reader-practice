

#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;

string int2string(int i) {
    stringstream converter;
    string ret;
    converter << i;
    converter >> ret;
    return ret;
}

int main(int argc, const char * argv[]) {
    string a = int2string(100);
    if (a != "100") {
        cout << "failed" << endl;
    } else {
        cout << "success" << endl;
    }
}
