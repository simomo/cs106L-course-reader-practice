#include <vector>
#include <deque>
#include <string>
#include <fstream>

using namespace std;

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

static void openMapFile(ifstream& gameMapFile) {}
static void loadGame(GameWorld& gameWorld, ifstream& gameMapFile) {}
static void runSimulation(GameWorld& gameWorld) {}