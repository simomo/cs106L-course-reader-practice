#include <map>
#include <set>

using namespace std;

typedef multimap<pair<int, char>, int> TransactionMap;

struct Nfa {
    TransactionMap transaction;
    set<int> acceptStatus;
    int startStatus;
};

void initNfa(Nfa& nfa) {

}

int main() {
    Nfa nfa;
    initNfa(nfa);

    set<int> currentStatus;
    currentStatus.insert(nfa.startStatus);

    string input = "0011";
    for (string::iterator c = input.begin(); c != input.end(); ++c) {
        set<int> incomingStatus;

        for (set<int>::iterator s = currentStatus.begin(); s != currentStatus.end(); ++s) {
            pair<TransactionMap::iterator, TransactionMap::iterator> selectedTransactions =
                nfa.transaction.equal_range(make_pair(*s, *c));

            for (TransactionMap::iterator ss = selectedTransactions.first; ss != selectedTransactions.second; ++ss) {
                incomingStatus.insert(ss->second);
            }
        }

        currentStatus.clear();
        // currentStatus(incomingStatus);
    }

    return 0;
}