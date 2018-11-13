#include <iostream>

using namespace std;

void printLineAndFile();
void printCompileDateTime();

int main() {
    printLineAndFile();
    printCompileDateTime();

    return 0;
}

void printLineAndFile() {
    cout << "Hi, I'm " << __FUNCTION__ << ", I'm in file " << __FILE__ << " line " << __LINE__ << endl;
}

void printCompileDateTime() {
    cout << "I'm compiled at " << __DATE__ << " " << __TIME__ << endl;
}