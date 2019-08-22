// 16. Suppose that you are given two vector<int> s with their elements stored in sorted order. Show
// how to print out the elements those vector s have in common in one line of code using the
// set_intersection algorithm and an appropriate iterator adaptor.
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {2, 4, 6, 8};
    set<int> intersection;

    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),
                     inserter(intersection, intersection.begin()));

    copy(intersection.begin(), intersection.end(), ostream_iterator<int>(cout, " , "));
}