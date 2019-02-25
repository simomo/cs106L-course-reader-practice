#include <vector>
#include <deque>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>  // system, rand
#include <chrono>  // sleep_for
#include <thread>  // sleep_for
#include <assert.h>
#include <algorithm>  // copy_if
#include <random>  // random things...
#include <iterator>  // back_insert

#include "myLib.h"

using namespace std;

const int maxFood = 6;
const char emptyTile = ' ';
const char wallTile = '#';
const char foodTile = '$';
const char snakeTile = '*';

struct PointT {
    int x;
    int y;

    PointT operator+(const PointT& right) {
        PointT result;
        result.x = this->x + right.x;
        result.y = this->y + right.y;

        return result;
    }

    string toString() {
        stringstream fmt;
        fmt << "[x=" << x << ", y=" << y << "]";
        return fmt.str();
    }
};

struct GameWorld {
    vector<string> gameMap;

    deque<PointT> snake;
    /* Only can be one of 4 values (0, 1), (0, -1), (1, 0), (-1, 0) */
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
                // cout << "snake size: " << gameWorld.snake.size();
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
    PointT newHead = gameWorld.snake[0] + gameWorld.snakeSpeed;
    gameWorld.snake.push_front(newHead);

    if (!(gameWorld.gameMap[newHead.y][newHead.x] == foodTile)) {
        PointT oldTail = gameWorld.snake.back();
        gameWorld.snake.pop_back();

        gameWorld.gameMap[oldTail.y][oldTail.x] = emptyTile;
    }

    gameWorld.gameMap[newHead.y][newHead.x] = snakeTile;

    if (gameWorld.snake.size() == 6) {
        return false;
    }
    return true;
}

/* 
 * Clear current screen and show the map
 */
static void refreshScreen(GameWorld& gameWorld) {
    system("clear");

    int mapRol = gameWorld.gameMap.size();
    for (int i=0; i<mapRol; i++) {
        cout << gameWorld.gameMap[i] << endl;
    }

    // Pause 1 second, so that we can see what happened
    this_thread::sleep_for(std::chrono::milliseconds(1000));
}

static void getPossibleSpeeds(const PointT& currentSpeed,  // IN
                              vector<PointT>& possibleSpeeds) {  // OUT
    assert(currentSpeed.x == 0 || currentSpeed.y == 0);
    assert(!(currentSpeed.x == 0 && currentSpeed.y == 0));

    if (currentSpeed.x == 0) {
        possibleSpeeds = {
            {0, currentSpeed.y},
            {1, 0},
            {-1, 0}
        };
    } else {
        possibleSpeeds = {
            {currentSpeed.x, 0},
            {0, 1},
            {0, -1}
        };
    }
}

static void pickOne(const vector<PointT> candidates,  // IN
                    GameWorld& gameWorld) {  // OUT
    int index;
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(0, candidates.size() - 1);
    index = dis(gen);

    // cout << candidates.size() << " " << index << endl;
    gameWorld.snakeSpeed = candidates[index];
}

/* 
 * Check the snake's status, make decision on the next move
 */
static void makeDecision(GameWorld& gameWorld) {
    // Get possible speeds
    vector<PointT> safeChoices;
    vector<PointT> possibleSpeeds;
    getPossibleSpeeds(gameWorld.snakeSpeed, possibleSpeeds);

    // cout << "possibleSpeeds" << endl;
    // for (auto i: possibleSpeeds) {
    //     cout << i.toString() << ' ';
    // }

    // Filter speeds to avoid crashing
    PointT preferOne = {0, 0};
    copy_if(
        possibleSpeeds.begin(),
        possibleSpeeds.end(),
        back_inserter(safeChoices),
        [&](PointT i) {
            if (preferOne.x != 0 || preferOne.y != 0) {  // shortcuts
                return false;
            }

            PointT next = gameWorld.snake[0] + i;
            if (gameWorld.gameMap[next.y][next.x] == foodTile) {
                preferOne = i;
                return true;
            } else {
                return gameWorld.gameMap[next.y][next.x] == emptyTile;
            }
        }
    );

    // cout << "safeChoices" << endl;
    // for (auto i: safeChoices) {
    //     cout << i.toString() << ' ';
    // }

    // Randomly choose one if there are more than one speeds
    if (preferOne.x != 0 || preferOne.y != 0) {
        gameWorld.snakeSpeed = preferOne;
    } else if (safeChoices.empty()) {
        pickOne(possibleSpeeds, gameWorld);
    } else {
        pickOne(safeChoices, gameWorld);
    }
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
        if (!moveSnake(gameWorld)) {
            break;
        }
        // putFood(gameWorld);  // drop new food into the map
    }

    displayResult(gameWorld);
}