// The distance function, defined in the <iterator> header, takes in two iterators and returns the
// number of elements spanned by that iterator range. For example, given a vector<int> , calling
// distance(v.begin(), v.end());
// returns the number of elements in the container.
// Modify the code from this chapter that prints the average of the values in a file so that it instead
// prints the average of the values in the file between 25 and 75. If no elements are in this range, you
// should print a message to this effect. You will need to use a combination of accumulate and
// distance .
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream f("data.txt");
    if (!f.is_open()) {
        cout << "Open data.txt failed" << endl;
        return 1;
    }

    int oneInt;  // stringstream is not needed here.
    while (f >> oneInt) {
        cout << oneInt << endl;
    }

    return 0;
}