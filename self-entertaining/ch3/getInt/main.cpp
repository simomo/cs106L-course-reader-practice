#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int getInt(void);

int main() {
    cout << "getInt returns: " << getInt() << endl;
}

int getInt(void) {
    string userInput;

    while (getline(cin, userInput)) {
        cout << "Please enter a int" << endl;

        stringstream converter;
        int expectedInt;
        converter << userInput;

        if (converter >> expectedInt) {
            string uselessStr;
            if (converter >> uselessStr) {
                cout << "uselessStr: " << uselessStr <<endl;
            } else {
                cout << "Int is " << expectedInt << endl;
                return expectedInt;
            }
        }
    }
}