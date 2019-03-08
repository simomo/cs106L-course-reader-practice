/* 
Implement the cipher:
T H E C O O K I E S A R E I N T H E F R I D G E
1 3 7 1 3 7 1 3 7 1 3 7 1 3 7 1 3 7 1 3 7 1 3 7
U K L D R V L L L T D Y F L U U K L G U P E J L
 */
#include <deque>
#include <iostream>

using namespace std;

struct Ring {
    deque<int> _deq;

    /* `:_deq(init)` vs `_deq = init`
      https://stackoverflow.com/a/926795/807695
     */
    Ring(deque<int>& init) {
        _deq = init;
    }

    // Ring(deque<int>& init): _deq(init) {}

    int get_and_next() {
        int r = _deq[0];
        
        _deq.pop_front();
        _deq.push_back(r);
        return r;
    }
};

int main() {
    deque<int> init({1, 3, 5});
    Ring ring(init);
    for (int i=0; i<10; ++i) {
        cout << ring.get_and_next() << endl;
    }

    return 0;
}