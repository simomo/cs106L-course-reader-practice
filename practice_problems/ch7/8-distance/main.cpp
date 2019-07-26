// 8. In n-dimensional space, the distance from a point (x 1 , x 2 , x 3 , ..., x n ) to the origin is [The formula] Write a function DistanceToOrigin that accepts a vector<double>
// representing a point in space and returns the distance from that point to the origin. Do not use any
// loops – let the algorithms do the heavy lifting for you. (Hint: Use the inner_product algorithm to
// compute the expression under the square root.)
#include <vector>
// #include <algorithm>
#include <numeric>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    vector<double> point = {1, 1, 1};

    cout << "result: " << sqrt(inner_product(point.begin(), point.end(), point.begin(), 0)) << endl;
    return 0;
}