#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string cipher = alphabet;
    random_shuffle(cipher.begin(), cipher.end());
    cout << cipher << endl;

    return 0;
}