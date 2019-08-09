// 12. Using the generate_n algorithm, the rand function, and a back_insert_iterator , show how to
// populate a vector with a specified number of random values. Then use accumulate to compute
// the average of the range.
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <random>

using namespace std;

const int N = 10;

int main() {

    // vector<int> results(N);  //  This shows why we need `back_inserter`, without it, we
                                //  have to hardcode a proper size here, otherwise it would
                                //  segment fault (`results() or results(0)`) or truncate
                                //  the ints (size < N) or cause some additional 0s are
                                //  printed (size > N).
    vector<int> results;
    mt19937 rng;

    // generate_n(results.begin(), N, rand);
    generate_n(back_inserter(results), N, rand);
    copy(results.begin(), results.end(), ostream_iterator<int>(cout, " "));

    cout << endl << "avg: " << accumulate(results.begin(), results.end(), 0) / N << endl;

    return 0;
}