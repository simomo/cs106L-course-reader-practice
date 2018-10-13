// Echo everything I heard
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    while (true) {
        string whatever;
        getline(cin, whatever);
        if (whatever == "quit") {
            cout << "Please say 'quit please'" << endl;
        } else if (whatever == "quit please") {
            cout << "Bye" << endl;
            break;
        }
        cout << "You said: " << whatever << endl;
    }

    return 0;
}
