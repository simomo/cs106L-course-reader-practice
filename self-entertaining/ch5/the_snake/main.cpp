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

int main() {
    ifstream mapFile;
    GetMapFileName(RetryLimit, mapFile);
    vector<string> worldMap = LoadWorldMap(mapFile);
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

}

static vector<string> LoadWorldMap(ifstream& mapFile) {
    vector<string> worldMap;

    return worldMap;
}