#include <fstream>
#include <string>
#include <map>
#include <iostream>


using namespace std;

bool initCountMap(map<string, int>& countMap) {
    return true;
}

int main() {
    // Read keywords.txt, init the keywords map
    map<string, int> countMap;
    if (!initCountMap(countMap)) {
        return -1;
    }

    // Open current file
    string fileName = __FILE__;
    ifstream currentFile(fileName);
    if (!currentFile.is_open()) {
        return -2;
    }

    // Iter each file, fill the keywords map
    string oneLine;
    while (getline(currentFile, oneLine)) {
        cout << oneLine << endl;
    }
    return 0;
}