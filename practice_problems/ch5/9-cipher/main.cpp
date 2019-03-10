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

string VigenereCipher(string input, deque<int> theKey, bool is_encryptor) {
    string ret;
    Ring ring(theKey);
    int tmpInt;
    char tmpChar;
    
    for (char& c: input) {
        tmpInt = (int) c;
        if (is_encryptor) {
            tmpInt += ring.get_and_next();
        } else {
            tmpInt -= ring.get_and_next();
        }
        tmpChar = (char) tmpInt;
        ret += tmpChar;
    }

    return ret;
}

int main() {
    deque<int> init({1, 3, 7});
    cout << VigenereCipher(VigenereCipher("Hi! I'm Duo Zhang", init, true), init, false) << endl;

    // The casting will do mod automatically
    cout << (char) 2 << (char) (2+256) << endl;
    return 0;
}