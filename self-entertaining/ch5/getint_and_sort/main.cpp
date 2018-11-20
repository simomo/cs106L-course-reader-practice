#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int numOfInt = 10;

static int GetInt();
static void SortValues(vector<int>& values);
static void CleanSStream(stringstream& ss);
static int findSmallestNumIndex(int startIndex, vector<int>& values);
static void swapInts(vector<int>& values, int indexA, int indexB);

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
    int smallestNumIndex;

    for (int i = 0; i < values.size(); ++i) {
        smallestNumIndex = findSmallestNumIndex(i, values);
        swapInts(values, i, smallestNumIndex);
    }
}


static void swapInts(vector<int>& values, int indexA, int indexB) {
    int tmp = values[indexA];
    values[indexA] = values[indexB];
    values[indexB] = tmp;
}


static int findSmallestNumIndex(int startIndex, vector<int>& values) {
    int smallestNum = values[startIndex];  // This can be omitted, only smallestNumIndex is necessary
    int smallestNumIndex = startIndex;

    for (int i = startIndex + 1; i < values.size(); ++i) {
        if (values[i] < smallestNum) {
            smallestNum = values[i];
            smallestNumIndex = i;
        }
    }

    cout << "Find the smallest num " << smallestNum << " at position " << smallestNumIndex << ", searching starts " << startIndex << "." << endl;
    return smallestNumIndex;
}


static void CleanSStream(stringstream& ss) {
    ss.str("");
    ss.clear();
}