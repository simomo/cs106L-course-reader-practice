#include <deque>
#include <sstream>
#include <iostream>

using namespace std;

struct Ring {
    deque<int> m_ring;

    // copy constructor & Ring(deque<int> ) constructor
    Ring() {}
    Ring(initializer_list<int> _l): m_ring(_l) {}
    Ring(deque<int> ring): m_ring(ring) {}
    Ring(Ring& _ring): m_ring(_ring.m_ring) {}

    // Read & Write
    int Read() {
        return m_ring[0];
    }

    void Write(int i) {
        m_ring[0] = i;
    }

    // CursorClockwise & CursorCounterClockwise
    Ring* CursorClockwise() {
        m_ring.push_front(m_ring.back());
        m_ring.pop_back();
        return this;
    }

    Ring* CursorCounterClockwise() {
        m_ring.push_back(m_ring[0]);
        m_ring.pop_front();
        return this;
    }

    // toString
    string toString() {
        stringstream fmt;
        fmt << "[deque<int>:";
        for (deque<int>::iterator i = m_ring.begin(); i != m_ring.end(); ++i) {
            fmt << " " << *i;
        }
        fmt << "]" << endl;

        return fmt.str();
    }
};

int main() {
    deque<int> init({1, 2, 3, 4, 5});
    Ring ring(init);
    Ring newRing(ring);

    Ring super({1, 2, 3, 4, 5});

    cout << ring.toString() << endl;
    cout << ring.CursorClockwise()->toString() << endl;
    cout << ring.CursorCounterClockwise()->toString() << endl;

    return 0;
}