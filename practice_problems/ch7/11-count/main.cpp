// 11. Implement the count algorithm for vector<int> s. Your function should have the prototype
// int count(vector<int>::iterator start, vector<int>::iterator stop, int
// element) and should return the number of elements in the range [ start , stop ) that are equal to
// element .
#include <vector>
#include <iostream>

using namespace std;

int count(vector<int>::iterator start, vector<int>::iterator stop, int ele) {
    int result = 0;
    for (vector<int>::iterator i = start; i != stop; ++i) {
        if (*i == ele) {
            ++result;
        }
    }

    return result;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8, 8, 8, 8, 8};
    cout << count(v.begin(), v.end(), 6) << endl;
    cout << count(v.begin(), v.end(), 8) << endl;
    return 0;
}