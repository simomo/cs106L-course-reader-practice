/*
 * Given a opened file, print its contents
 */
#ifndef open_file_print
#define open_file_print
#include "read_file_name_open.cpp"

void printFile(ifstream& theFile) {
    if (!theFile.is_open()) {
        exit(-1);
    }

    string oneLine;
    while(getline(theFile, oneLine)) {
        cout << oneLine;
    }
}

int main() {
    ifstream theFile;
    openFile(theFile);
    printFile(theFile);
    return 0;
}

#endif