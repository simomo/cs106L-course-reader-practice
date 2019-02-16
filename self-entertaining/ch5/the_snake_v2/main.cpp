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

        cout << "Your input " << fileName << " can not be opened" << endl;
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
static bool moveSnake(GameWorld& gameWorld) {

}

/* 
 * Clear current screen and show the map
 */
static void refreshScreen(GameWorld& gameWorld) {
    int mapRol = gameWorld.gameMap.size();

    for (int i=0; i<mapRol; i++) {
        cout << gameWorld.gameMap[i] << endl;
    }
}

/* 
 * Check the snake's status, make decision on the next move
 */
static void makeDecision(GameWorld& gameWorld) {

}

static void displayResult(GameWorld& gameWorld) {

}

static void runSimulation(GameWorld& gameWorld) {
    // Q: Check if I'm right about these steps :P
    // A: I was terribly wrong:
    //     1. it only implements one step/move of the snake,
    //     2. it doesn't consider when the game ends.
    //     3. it doesn't consider when the snake crash

    // Q: Why is my thinking so shallow?
    /* A: I always tend to satisfy with my first idea about one problem, I should
          be more patient/confidence and give myself more time to think deeper.
     */
    while (gameWorld.snake.size() < maxFood) {
        refreshScreen(gameWorld);
        makeDecision(gameWorld);
        if (moveSnake(gameWorld)) {
            break;
        }
        break;  // Test code
        // putFood(gameWorld);  // drop new food into the map
    }

    displayResult(gameWorld);
}