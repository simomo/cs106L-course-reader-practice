#include <fstream>
#include <iostream>

using namespace std;

int main() {
    int intValue;
    string oneLine;

    cout << "Please input a int then a string" << endl;
    cin >> intValue;
    getline(cin, oneLine);
    cout << "OK, got you! The int is " << intValue << ", while the string is " << oneLine << endl;
}