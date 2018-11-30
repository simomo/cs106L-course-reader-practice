#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int RetryLimit = 3;

struct GameT {
    vector<string> gameMap;

};

static void GetMapFileName(int retryLimit, ifstream& mapFile);
static vector<string> LoadWorldMap(ifstream& mapFile);
static void PrintVector(vector<string>& values);

int main() {
    ifstream mapFile;
    GetMapFileName(RetryLimit, mapFile);
    vector<string> worldMap = LoadWorldMap(mapFile);
    PrintVector(worldMap);
}

static void GetMapFileName(int retryLimit, ifstream& mapFile) {
    string fileName;
    cout << "Please enter the name of map file: " << endl;

    while (retryLimit) {
        if (!getline(cin, fileName)) {
            cout << "You just entered an invalid file name:" << fileName << endl;
            retryLimit--;
            continue;
        }

        mapFile.open(fileName);
        if (!mapFile.is_open()) {
            cout << "Open file " << fileName << " failed, please try again" << endl;
            retryLimit--;
            mapFile.clear();  // ch3-p10 readme: It seems that `f.clear()` is not necessariy
            continue;
        }
        cout << "Open file " << fileName << " successfully!" << endl;
        break;
    }

    cout << "Will use default one: sample_map.txt" << endl;
    mapFile.open("sample_map.txt");
}

static vector<string> LoadWorldMap(ifstream& mapFile) {
    vector<string> worldMap;

    string oneLine;
    while(getline(mapFile, oneLine)) {
        // cout << oneLine << endl;
        worldMap.push_back(oneLine);
    }

    return worldMap;
}

static void PrintVector(vector<string>& values) {
    string oneLine;
    vector<string>::iterator it;
    for (it = values.begin(); it != values.end(); ++it) {
        cout << *it << endl;
    }
}