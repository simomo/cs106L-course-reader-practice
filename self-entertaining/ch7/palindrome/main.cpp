#include <string>
#include <cassert>

using namespace std;

bool IsPalindrome(string input) {
    for (int i=0; i < input.size() / 2; ++i) {
        if (input[i] != input[input.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    assert(IsPalindrome("abcba"));
    return 0;
}