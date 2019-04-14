#include <map>
#include <set>
#include <iostream>

using namespace std;

typedef multimap<pair<int, char>, int> TransactionMap;

struct Nfa {
    TransactionMap transaction;
    set<int> acceptStatus;
    int startStatus;
};

void initNfa(Nfa& nfa) {
    // Init transcations
    nfa.transaction.insert(make_pair(make_pair(0, '0'), 0));
    nfa.transaction.insert(make_pair(make_pair(0, '1'), 0));

    nfa.transaction.insert(make_pair(make_pair(0, '0'), 1));
    nfa.transaction.insert(make_pair(make_pair(1, '0'), 2));

    nfa.transaction.insert(make_pair(make_pair(0, '1'), 3));
    nfa.transaction.insert(make_pair(make_pair(3, '1'), 4));

    // Init startStatus
    nfa.startStatus = 0;
}

void printSet(set<int>& s) {
    for (set<int>::iterator i = s.begin(); i != s.end(); ++i) {
        cout << *i << endl;
    }
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

        currentStatus = incomingStatus;
    }

    cout << "result: " << endl;
    printSet(currentStatus);
    return 0;
}