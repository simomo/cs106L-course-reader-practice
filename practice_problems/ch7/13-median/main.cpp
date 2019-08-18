// 13. The median of a range of data is the value that is bigger than half the elements in the range and
// smaller than half the elements in a range. For data sets with odd numbers of elements, this is the
// middle element when the elements are sorted, and for data sets with an even number of elements
// it is the average of the two middle elements. Using the nth_element algorithm, write a function
// that computes the median of a set of data
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int findMed(vector<int>& v) {
    int median;
    if (v.size() % 2 == 0) {
        nth_element(v.begin(), v.begin() + v.size()/2, v.end());
        int v1 = *(v.begin() + v.size()/2);
        nth_element(v.begin(), v.begin() + v.size()/2 - 1, v.end());
        int v2 = *(v.begin() + v.size()/2 - 1);
        median = (v1 + v2) / 2;
        cout << median << endl;
    } else {
        nth_element(v.begin(), v.begin() + v.size()/2, v.end());
        median = *(v.begin() + v.size()/2);
        cout << median << endl;
    }
    return median;
}

int main () {
    vector<int> v = {1, 2, 3, 4, 4, 6, 7, 8};
    cout << findMed(v) << endl;
    vector<int> vv = {1, 2, 3, 7, 8};
    cout << findMed(vv) << endl;
    return 0;
}