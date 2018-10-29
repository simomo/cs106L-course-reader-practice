/*
 * Write this file after reading this article:
 * https://gehrcke.de/2011/06/reading-files-in-c-using-ifstream-dealing-correctly-with-badbit-failbit-eofbit-and-perror/
 * 
 */
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void processLine(string& oneLine) {
    cout << oneLine << endl;
}


int main() {
    string fileName;
    string line;

    cin >> fileName;
    cout << "I'm opening file: " << fileName << " for you" << endl;
    ifstream f (fileName.c_str());
    while (getline(f, line)) {
        processLine(line);
    }
    return 0;
}
