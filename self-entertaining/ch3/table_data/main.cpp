#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <assert.h>

#define SOURCE_FILE_NAME "table-data.txt"
#define DEST_FILE_NAME "dest.txt"

using namespace std;

const int columnWidth = 20;
const int numOfRows = 3;
const int numOfColumns = 3;

/*
 * Print a header like(number of columns is 3):
 * 
 * ---------------+---------------+--------------
 * 
 */
void printTableHeader() {
    assert(numOfColumns >= 2);

    for (int i=0; i<numOfColumns-1; ++i) {
        cout << setfill('-') << setw(columnWidth) << "+";
    }

    cout << setw(columnWidth) << "" << setfill(' ') << endl;
}

void printEachBodyLine(const int index, const int intValue, const double doubleValue) {
    cout << setw(columnWidth-1) << index << "|" << setw(columnWidth-1) << intValue\
    << "|" << setw(columnWidth) << doubleValue << endl; 
}

void printTableBody() {
    ifstream sourceFile(SOURCE_FILE_NAME);
    int intValue;
    double doubleValue;

    for (int i=0; i<numOfRows; ++i) {
        sourceFile >> intValue >> doubleValue;
        printEachBodyLine(i+1, intValue, doubleValue);
    }
}

void printTableBodyV2() {
    ifstream sourceFile(SOURCE_FILE_NAME);

    int intValue;
    double doubleValue;

    int rowNum = 0;
    while (sourceFile >> intValue >> doubleValue) {
        ++rowNum;
        printEachBodyLine(rowNum, intValue, doubleValue);
    }
}

int main(int argc, char* argv[]) {
    printTableHeader();

    if (argc == 1) {
        printTableBody();
    } else {
        printTableBodyV2();
    }

    return 0;
}