

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// get one line from stdin
string GetLine() {
    string ret;
    getline(cin, ret, '\n');
    cout << "Got: " << ret << endl;
    return ret;
}

// extract a int
int get_int() {
    int ret;
    
    while (true) {
        stringstream converter;
        converter << GetLine();
        if (converter >> ret) {
            char remains;
            if (converter >> remains) {
                cout << "Unexpected character: " << remains << endl;
            } else {
                return ret;
            }
        } else {
            cout << "Please enter a int" << endl;
        }
    }
}

// extract a float
float get_float() {
    float ret;
    
    while (true) {
        stringstream converter;
        converter << GetLine();
        if (converter >> ret) {
            char remains;
            if (converter >> remains) {
                cout << "Unexpected character: " << remains << endl;
            } else {
                return ret;
            }
        } else {
            cout << "Please enter a float" << endl;
        }
    }
}

int main(int argc, const char * argv[]) {
    int a = get_int();
    float b = get_float();
}
