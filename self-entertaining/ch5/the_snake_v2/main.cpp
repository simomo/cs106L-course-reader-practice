#include <vector>
#include <deque>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "myLib.h"

using namespace std;

const int maxFood = 20;
const char emptyTile = ' ';
const char wallTile = '#';
const char foodTile = '$';
const char snakeTile = '*';

struct PointT {
    int x;
    int y;
};

struct GameWorld {
    vector<string> gameMap;

    deque<PointT> snake;
    PointT snakeSpeed;
};

static void initGame(GameWorld& gameWorld);
static void openMapFile(ifstream& gameMapFile);
static void loadGame(GameWorld& gameWorld, ifstream& gameMapFile);
static void runSimulation(GameWorld& gameWorld);

int main() {
    ifstream gameMapFile;
    openMapFile(gameMapFile);
}

int _main() {
    GameWorld gameWorld;
    initGame(gameWorld);
    runSimulation(gameWorld);
    return 0;
}

static void initGame(GameWorld& gameWorld) {
    ifstream gameMapFile;
    openMapFile(gameMapFile);
    loadGame(gameWorld, gameMapFile);
}

static void openMapFile(ifstream& gameMapFile) {
    string fileName;

    while (true) {
        cout << "Please enter the map's file name: ";
        fileName = GetLine();
        gameMapFile.open(fileName);
        // gameMapFile.open(fileName.c_str());
        if (gameMapFile.is_open()) break;

        cout << "Your input " << fileName << " can not be opened";
    }
}

static void loadGame(GameWorld& gameWorld, ifstream& gameMapFile) {
    gameMapFile >> gameWorld.snakeSpeed.x >> gameWorld.snakeSpeed.y;

    /*
     * # Why we have this `dummy`?
     *  the first call to getline after using the stream extraction operator
     * will return the empty string because the newline character delimiting
     * the data is still waiting to be read. 
     */
    string dummy;
    getline(gameMapFile, dummy);

    // TODO: get lenght and width, then resize
    string oneLine;
    while (getline(gameMapFile, oneLine)) {
        
    }

}
static void runSimulation(GameWorld& gameWorld) {}