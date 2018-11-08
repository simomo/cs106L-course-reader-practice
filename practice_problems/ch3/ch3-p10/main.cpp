/* 
Write a function OpenFile that accepts as input an ifstream by reference and prompts the user
for the name of a file. If the file can be found, OpenFile should return with the ifstream opened
to read that file. Otherwise, OpenFile should print an error message and reprompt the user.
(Hint: If you try to open a nonexistent file with an ifstream , the stream goes into a fail state and you
will need to use .clear() to restore it before trying again).
*/
#include <fstream>
#include <iostream>

using namespace std;

ifstream& OpenFile(ifstream&);

int main() {
    ifstream f;
    ifstream& openedFile = OpenFile(f);

    string oneLine;
    cout << "The content: " << endl;
    while(getline(openedFile, oneLine)) {
        cout << oneLine << endl;
    }
}

ifstream& OpenFile(ifstream& f) {
    cout << "Please input the file name you want to open: " << endl;
    
    string fileName;
    while (getline(cin, fileName)) {
        cout << "[Before open] f.fail is " << boolalpha << f.fail() << endl;
        f.open(fileName.c_str());
        cout << "[After open] f.fail is " << boolalpha << f.fail() << endl;

        if (!f) {
            cout << "Open file " << fileName << " failed" << endl;
            // f.clear();
            continue;
        }

        return f;
    }
}