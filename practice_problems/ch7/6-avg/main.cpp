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
#include <vector>
#include <numeric>
#include <iterator>
#include <algorithm>

using namespace std;

// Filter
bool filter(int v) {
    return !(v > 25 and v < 75);
}

int main() {
    ifstream f("data.txt");
    vector<int> values;

    // Approch 1 of reading from file to a vector<int>
    // if (!f.is_open()) {
    //     cout << "Open data.txt failed" << endl;
    //     return 1;
    // }

    // int oneInt;  // stringstream is not needed here.
    // while (f >> oneInt) {
    //     cout << oneInt << endl;
    //     values.push_back(oneInt);
    // }

    // Approch 2 reading from file to a vector<int>
    istream_iterator<int> fi(f);
    copy(fi, istream_iterator<int>(), back_inserter(values));
    // I was seeking a way to chain `copy` and `accumulate`, until I found this:
    // https://stackoverflow.com/a/6743171, a very nice explaination for why
    // I can't do that.

    values.erase(remove_if(values.begin(), values.end(), filter), values.end());

    int sum = accumulate(values.begin(), values.end(), 0);
    cout << "sum: " << sum << endl;
    cout << "avg: " << sum / values.size() << endl;

    return 0;
}