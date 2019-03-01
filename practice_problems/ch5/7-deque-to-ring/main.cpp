#include <deque>

using namespace std;

struct Ring {
    deque<int> m_ring;

    // copy constructor & Ring(deque<int> ) constructor
    Ring() {}
    Ring(initializer_list<int> _l): m_ring(_l) {}
    Ring(deque<int> ring): m_ring(ring) {}
    Ring(Ring& _ring): m_ring(_ring.m_ring) {}

    // Read & Write

    // CursorClockwise & CursorCounterClockwise
};

int main() {
    deque<int> init({1, 2, 3, 4, 5});
    Ring ring(init);
    Ring newRing(ring);

    Ring super({1, 2, 3, 4, 5});

    return 0;
}