#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

bool IsPalindrome(string input) {
    for (int i=0; i < input.size() / 2; ++i) {
        if (input[i] != input[input.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool IsPalindrome1(string input) {
    string reversed = input;
    reverse(reversed.begin(), reversed.end());
    return reversed == input;
}

bool IsPalindrome2(string input) {
    return equal(input.begin(), input.begin() + input.size()/2, input.rbegin());
}

// 3
bool IsNotAlpha(char c) {
    return !isalpha(c);
}
bool IsPalindrome3(string input) {
    // The remove_if & erase pattern: https://stackoverflow.com/a/42116415
    input.erase(remove_if(input.begin(), input.end(), IsNotAlpha), input.end());
}

int main() {
    assert(IsPalindrome("abcba"));
    assert(IsPalindrome1("abcba"));
    assert(IsPalindrome2("abcba"));
    return 0;
}