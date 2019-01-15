#include <vector>
#include <string>

using namespace std;

struct PointT {
    int x;
    int y;
};

struct GameWorld {
    vector<string> gameMap;

    vector<PointT> snake;
    PointT snakeSpeed;
};

static void initGame(GameWorld& gameWorld);
static void runSimulation(GameWorld& gameWorld);

int main() {
    GameWorld gameWorld;
    initGame(gameWorld);
    runSimulation(gameWorld);
    return 0;
}