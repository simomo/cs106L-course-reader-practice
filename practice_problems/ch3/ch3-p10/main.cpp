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