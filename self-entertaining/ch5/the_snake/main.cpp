#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

struct Coordinate {
    int x;
    int y;
};

struct GameT {
    vector<string> gameMap;
    int mapWidth;
    int mapHeight;

    Coordinate headPos;
    Coordinate speed;

    int snakeLen;
};

const int RetryLimit = 3;
const char Wall = '#';
const char Food = '$';
const char Empty = ' ';

const vector<Coordinate> FourDir = {{0, 0}, {1, 0}, {1, 0}, {1, 1}};

static void GetMapFileName(int retryLimit, ifstream& mapFile);
static vector<string> LoadWorldMap(GameT& theGame, ifstream& mapFile);
static void PrintVector(vector<string>& values);
static void GenerateInitParams(GameT& theGame);
static Coordinate GenerateRandPos(int mapWidth, int mapHeight);
static inline bool PosIsEmpty(const GameT& theGame, const Coordinate& candidate);
static Coordinate GenerateRandSpeed(void);
static inline Coordinate GenerateRandSpeed(void);

int main() {
    ifstream mapFile;
    GameT theGame;

    GetMapFileName(RetryLimit, mapFile);
    LoadWorldMap(theGame, mapFile);
    PrintVector(theGame.gameMap);

    GenerateInitParams(theGame);

    while(!Win(theGame)) {
        OneStep(theGame);
        Display(theGame);
        RunAI(theGame);
    }
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

static vector<string> LoadWorldMap(GameT& theGame, ifstream& mapFile) {
    vector<string> worldMap;

    string oneLine;
    while(getline(mapFile, oneLine)) {
        // cout << oneLine << endl;
        worldMap.push_back(oneLine);
    }

    theGame.gameMap = worldMap;

    theGame.mapWidth = worldMap[0].size();
    theGame.mapHeight = worldMap.size();
}

static void PrintVector(vector<string>& values) {
    string oneLine;
    vector<string>::iterator it;
    for (it = values.begin(); it != values.end(); ++it) {
        cout << *it << endl;
    }
}

static void GenerateInitParams(GameT& theGame) {
    Coordinate candidate;
    while (true) {
        candidate = GenerateRandPos(theGame.mapWidth, theGame.mapHeight);
        if (PosIsEmpty(theGame, candidate)) {
            break;
        }
    }

    theGame.headPos = candidate;
    theGame.speed = GenerateRandSpeed();

    theGame.snakeLen = 1;
}

static Coordinate GenerateRandPos(int mapWidth, int mapHeight) {
    Coordinate point;
    point.x = rand() % mapWidth;
    point.y = rand() % mapHeight;
}


static inline bool PosIsEmpty(const GameT& theGame, const Coordinate& candidate) {
    return theGame.gameMap[candidate.y][candidate.x] == Empty;
}

static inline Coordinate GenerateRandSpeed(void) {
    return FourDir[rand() % 4];
}