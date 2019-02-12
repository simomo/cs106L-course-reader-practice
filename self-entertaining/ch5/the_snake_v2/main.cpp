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

    int numRow;
    int numCol;
};

static void initGame(GameWorld& gameWorld);
static void openMapFile(ifstream& gameMapFile);
static void loadGame(GameWorld& gameWorld, ifstream& gameMapFile);
static void runSimulation(GameWorld& gameWorld);
static PointT makePoint(int x, int y);

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
    gameMapFile >> gameWorld.numRow >> gameWorld.numCol;
    /* # `resize` vs `reserve` vs `push_back`
     *
     * https://stackoverflow.com/a/7397862/807695
     * https://stackoverflow.com/a/4821069/807695
     * https://stackoverflow.com/a/1902900/807695
     * 
     */
    gameWorld.gameMap.resize(gameWorld.numRow);
    gameMapFile >> gameWorld.snakeSpeed.x >> gameWorld.snakeSpeed.y;

    /*
     * # Why we have this `dummy`?
     *  the first call to getline after using the stream extraction operator
     * will return the empty string because the newline character delimiting
     * the data is still waiting to be read. 
     */
    string dummy;
    getline(gameMapFile, dummy);

    // int lineNum = 0;
    // string oneLine;
    // while (getline(gameMapFile, oneLine)) {
    //     gameWorld.gameMap[lineNum] = oneLine;
    //     lineNum++;
    // }
    for (int i=0; i<gameWorld.numRow; i++) {
        string oneLine;
        if (getline(gameMapFile, oneLine)) {
            gameWorld.gameMap[i] = oneLine;
            // Find the snake head
            string::size_type snakePos = oneLine.find(snakeTile);
            if (snakePos != string::npos) {
                gameWorld.snake.push_back(makePoint(snakePos, i));
            }
        }
    }

}

static PointT makePoint(int x, int y) {
    PointT result;
    result.x = x;
    result.y = y;
    return result;
}

/* 
 * According to the gameWorld.snakeSpeed, update the snake's position as well as
 * the map
 */
static void moveSnake(GameWorld& gameWorld) {

}

/* 
 * Clear current screen and show the map
 */
static void refreshScreen(GameWorld& gameWorld) {

}

/* 
 * Check the snake's status, make decision on the next move
 */
static void makeDecision(GameWorld& gameWorld) {

}

static void runSimulation(GameWorld& gameWorld) {
    // TODO: Check if I'm right about these steps :P
    moveSnake(gameWorld);
    refreshScreen(gameWorld);
    makeDecision(gameWorld);
    // putFood(gameWorld);  // drop new food into the map
}