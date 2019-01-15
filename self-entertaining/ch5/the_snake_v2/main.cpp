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

int main() {
    return 0;
}