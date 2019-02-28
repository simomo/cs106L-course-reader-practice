#include <deque>

using namespace std;

struct Ring {
    deque<int> m_ring;

    // copy constructor & Ring(deque<int> ) constructor
    Ring() {}
    Ring(deque<int> ring): m_ring(ring) {}

    // Read & Write

    // CursorClockwise & CursorCounterClockwise
};

int main() {
    deque<int> init({1, 2, 3, 4, 5});
    Ring ring(init);

    return 0;
}