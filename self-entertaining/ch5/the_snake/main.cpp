#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string sampleMap = "sample_map.txt";

vector<vector<string> > LoadWorldMap(string fileName);

int main() {
    vector<vector<string> > worldMap = LoadWorldMap("");
}

vector<vector<string> > LoadWorldMap(string fileName) {
    vector<vector<string> > worldMap;

    if (fileName.empty()) {
        fileName = sampleMap;
    }

    return worldMap;    
}