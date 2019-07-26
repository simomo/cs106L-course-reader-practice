// 9. Write a function BiasedSort that accepts a vector<string> by reference and sorts the vector
// lexicographically, except that if the vector contains the string “Me First,” that string is always at
// the front of the sorted list. This may seem like a silly problem, but can come up in some
// circumstances. For example, if you have a list of songs in a music library, you might want songs
// with the title “Untitled” to always appear at the top
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool anyOneFirst(string v) {
    // cout << (v == "Me First") << endl;
    return v == "Me First";
}

int main() {
    vector<string> values = {"A", "B", "C", "Me First", "D"};

    sort(values.begin(), values.end(), greater<string>());
    remove_if(values.begin(), values.end(), anyOneFirst);
    reverse(values.begin(), values.end());

    for (vector<string>::iterator i = values.begin(); i != values.end(); ++i) {
        cout << *i << endl;
    }

    return 0;
}