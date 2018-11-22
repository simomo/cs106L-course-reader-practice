#include <vector>
#include <iostream>

using namespace std;

void PrintVector(vector<int>& values) {
    cout << "Result: ";
    for (size_t i = 0; i < values.size(); ++i) {
        cout << values[i] << " ";
    }

    cout << endl;
}

int main() {
    vector<int> intV1(15);
    PrintVector(intV1);

    vector<int> intV2(15, 10);
    PrintVector(intV2);

    intV2.resize(20, 0);
    PrintVector(intV2);

    intV2.resize(17);
    PrintVector(intV2);

    intV2.resize(7, 4);  // the second param will be optimized
    PrintVector(intV2);

    intV2.erase(intV2.begin() + 4);  // Remove the 4th element
    PrintVector(intV2);

    intV2.pop_back();
    PrintVector(intV2);

    intV2.clear();
    PrintVector(intV2);

    return 0;
}

// Output:
// $ ./out.exe
// Result: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// Result: 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
// Result: 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 0 0 0 0 0
// Result: 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 0 0
// Result: 10 10 10 10 10 10 10
// Result: 10 10 10 10 10 10
// Result: 10 10 10 10 10
// Result: