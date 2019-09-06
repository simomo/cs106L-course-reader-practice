#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string cipher = alphabet;
    random_shuffle(cipher.begin(), cipher.end());

    string message = "HiIloveYou";
    string encryptedMsg(message);
    int i = 0;
    for(i; i < message.size(); ++i) {
        char c = message[i];
        c = tolower(c);

        size_t index = alphabet.find(c);
        if (index == string::npos) {
            continue;
        }

        encryptedMsg[i] = cipher[index];
    }
    cout << alphabet << endl;
    cout << cipher << endl;
    cout << message << endl;
    cout << encryptedMsg << endl;

    return 0;
}