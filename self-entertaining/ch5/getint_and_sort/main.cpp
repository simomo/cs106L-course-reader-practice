#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int numOfInt = 10;

static int GetInt();
static void SortValues(vector<int>& values);
static void CleanSStream(stringstream& ss);

int main() {
    vector<int> values;

    for (int i = 0; i < numOfInt; ++i) {
        values.push_back(GetInt());
    }

    SortValues(values);

    for (int i = 0; i < numOfInt; ++i) {
        cout << values[i] << ", " << endl;
    }

    return 0;
}


static int GetInt() {
    string userInput;
    stringstream converter;
    int theInt;
    string uselessPart;

    cout << "Please enter a int" << endl;
    while(getline(cin, userInput)) {
        converter << userInput;

        if (converter >> theInt && ! (converter >> uselessPart)) {
            cout << "Thank you, you just input " << theInt << endl;
            return theInt;
        }

        cout << "Oops, your input " << userInput << " is not expected, because " << uselessPart << ", please try again" << endl;
        CleanSStream(converter);
    }
}


static void SortValues(vector<int>& values) {
}


static void CleanSStream(stringstream& ss) {
    ss.str("");
    ss.clear();
}