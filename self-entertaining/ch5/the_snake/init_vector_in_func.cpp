#include <iostream>
#include <vector>

using namespace std;

struct S {
    vector<int> v;
};

void initS(S& s) {
    s.v = {1, 2, 3};
}

int main() {
    S s;
    initS(s);

    for (int i = 0; i < s.v.size(); ++i) {
        cout << s.v[i];
    }

    return 0;
}