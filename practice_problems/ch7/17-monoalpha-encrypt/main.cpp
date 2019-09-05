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
    transform(message.begin(), message.end(), encryptedMsg.begin(),
        [](char c){
            return tolower(c);
        });

    cout << cipher << endl;
    cout << message << endl;
    cout << encryptedMsg << endl;

    return 0;
}