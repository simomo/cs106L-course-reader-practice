#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <sstream>


using namespace std;

bool initCountMap(map<string, int>& countMap) {
    ifstream kw("keywords.txt");
    if (!kw.is_open()) {
        return false;
    }

    string oneLine;
    while (getline(kw, oneLine)) {
        countMap[oneLine] = 0;
    }
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
    stringstream ss;
    while (getline(currentFile, oneLine)) {
        // while(true) => while true 
        for (int i = 0; i < oneLine.size(); ++i) {
            if (ispunct(oneLine[i]) && oneLine[i] != '_') {
                oneLine[i] = ' ';
            }
        }
        ss << oneLine;
        
        string oneWord;
        while (ss >> oneWord) {
            if (countMap.count(oneWord)) {
                countMap[oneWord] += 1;
            }
        }

        ss.clear();
        ss.str("");
    }

    // Iter the keywords map, print the non-zero pairs
    for (map<string, int>::iterator i = countMap.begin(); i != countMap.end(); ++i) {
        if (i->second > 0) {
            cout << i-> first << " " << i->second << endl;
        }
    }
    return 0;
}