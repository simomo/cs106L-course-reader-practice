/*
 * Implement a function, which reads a file name from a user, and open it,
 * if failed, let the user retry
 */
#ifndef read_file_name_open
#define read_file_name_open
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void openFile(ifstream& theFile) {
    while (true) {
        cout << "Please input a file name: ";

        string fileName;
        if (getline(cin, fileName)) {
            theFile.open(fileName);
            if (theFile.is_open()) {
                break;
            }

            theFile.clear();
        }
    }
}

// int main() {
//     ifstream theFile;
//     openFile(theFile);
// }

#endif