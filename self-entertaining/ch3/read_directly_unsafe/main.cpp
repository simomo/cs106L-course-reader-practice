#include <fstream>
#include <iostream>

using namespace std;

int main() {
    string userName;
    string passwd;
    bool selfDestroy;

    cin >> userName >> passwd;
    if (userName == "root" && passwd == "passwd") {
        cout << "Login Succeed" << endl;

        cout << "Self destroy?";
        cout << " (Is the cin failed?: " << boolalpha << cin.fail() << ")" << endl;
        cin >> boolalpha >> selfDestroy;

        if (selfDestroy) {
            cout << "You Are Doomed!" << endl;
        }
    }

    return 0;
}