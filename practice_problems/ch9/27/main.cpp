#include <cstdlib>
#include <ctime>

#include <iostream>

using namespace std;

class RandomGenerator {
public:
    RandomGenerator();

    double next();

private:
    static bool seeded;
};

bool RandomGenerator::seeded(false);

RandomGenerator::RandomGenerator() {
    if (!seeded) {
        srand((unsigned int)time(NULL));
        seeded = true;
        cout << "seeded!" << endl;
    }
}

double RandomGenerator::next() {
    return (double) rand() / RAND_MAX;
}

int main() {
    RandomGenerator r1;
    RandomGenerator r2;

    cout << r1.next() << endl;
    cout << r2.next() << endl;
}