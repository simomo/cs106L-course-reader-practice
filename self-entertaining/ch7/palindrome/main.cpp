#include <string>
#include <cassert>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>
#include <iterator>

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

// 3: remove all not-alpha characters
bool IsNotAlpha(char c) {
    return !isalpha(c);
}

bool IsPalindrome3(string input) {
    // The remove_if & erase pattern: https://stackoverflow.com/a/42116415
    input.erase(remove_if(input.begin(), input.end(), IsNotAlpha), input.end());
    return equal(input.begin(), input.begin() + input.size()/2, input.rbegin());
}

// 4: be case-insensitive
bool IsPalindrome4(string input) {
    input.erase(remove_if(input.begin(), input.end(), IsNotAlpha), input.end());
    // About the double colon: https://stackoverflow.com/a/4269064
    transform(input.begin(), input.end(), input.begin(), ::toupper);

    return equal(input.begin(), input.begin() + input.size()/2, input.rbegin());
}

// 5: word level pelindrome
    // 1. Clean up the input: strip out everything except letters and spaces, then convert the result to upper
    // case.
    // 2. Break up the input into a list of words.
    // 3. Return whether the list is the same forwards and backwards.
bool IsNotAlphaOrSpace(char c) {
    return !isalpha(c) || !isspace(c);
}

bool IsWordPalindrome(string input) {
    input.erase(remove_if(input.begin(), input.begin() + input.size()/2, IsNotAlphaOrSpace),
                input.end());
    transform(input.begin(), input.end(), input.begin(), ::toupper);

    stringstream tokenizer(input);
    vector<string> tokens;

    // string --(stringstream)--> stream --(istream_iterator)--> iterator
    tokens.insert(tokens.begin(), istream_iterator<string>(tokenizer), istream_iterator<string>());
    return equal(tokens.begin(), tokens.begin() + tokens.size()/2, tokens.rbegin());
}

int main() {
    assert(IsPalindrome("abcba"));
    assert(IsPalindrome1("abcba"));
    assert(IsPalindrome2("abcba"));
    assert(IsPalindrome3("a: bcba"));

    assert(IsPalindrome3("a: Bcba") == false);
    assert(IsPalindrome4("a: Bcba"));

    assert(IsWordPalindrome("This is this!"));
    return 0;
}