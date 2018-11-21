#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

const int timesOfUserInput = 10;

static void GatherUserInputAndSort(vector<int>& values, int timesOfUserInput);
static int GetInt(void);
static int FindIndexToInsert(vector<int>& values, int value);
static void ClearConverter(stringstream& converter);

int main() {
    vector<int> values;
    int i = 0;
    GatherUserInputAndSort(values, timesOfUserInput);

    for (i; i < values.size(); ++i) {
        cout << values[i] << endl;
    }
    return 0;
}

static void GatherUserInputAndSort(vector<int>& values, int timesOfUserInput) {
    for (int i = 0; i < timesOfUserInput; ++i) {
        int value = GetInt();
        int indexToInsert = FindIndexToInsert(values, value);
        
        values.insert(values.begin() + indexToInsert, value);
    }
}

static int GetInt() {
    int ret;
    stringstream converter;
    string userInput;
    string useleseStr;

    while(getline(cin, userInput)) {
        converter << userInput;

        if (converter >> ret && !(converter >> useleseStr)) {
            return ret;
        }

        ClearConverter(converter);
    }
}

static void ClearConverter(stringstream& converter) {
    converter.str("");
    converter.clear();
}

static int FindIndexToInsert(vector<int>& values, int value) {
    for (int i = 0; i < values.size(); ++i) {
        if (values[i] > value) {
            return i;
        }
    }

    return values.size();
}