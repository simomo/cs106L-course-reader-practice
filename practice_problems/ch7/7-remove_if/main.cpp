// 7. Using remove_if and a custom callback function, write a function RemoveShortWords that
// accepts a vector<string> and removes all strings of length 3 or less from it. This function can be
// written in two lines of code if you harness the algorithms correctly
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool filter(string s) {
    return s.size() <= 3;
}

void RemoveShortWords(vector<string>& words) {
    words.erase(remove_if(words.begin(), words.end(), filter), words.end());
}

int main() {
    vector<string> words = {"a", "aa", "aaa", "aaaa", "aaaaa"};
    RemoveShortWords(words);

    for (vector<string>::iterator i = words.begin(); i != words.end(); ++i) {
        cout << *i << endl;
    }
    return 0;
}