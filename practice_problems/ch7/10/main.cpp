// 10. Write a function CriticsPick that accepts a map<string, double> of movies and their ratings
//     (between 0.0 and 10.0) and returns a set<string> of the names of the top ten movies in the map .
//     If there are fewer than ten elements in the map , then the resulting set should contain every string
//     in the map . (Hint: Remember that all elements in a map<string, double> are stored internally as
//     pair<string, double> )
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

bool compare(vector<pair<string, double>>::iterator p1, vector<pair<string, double>>::iterator p2) {
    return p1->second < p2->second;
}

int main() {
    map<string, double> allMovies = {
        {"The 5th element", 9.4},
        {"Armageddon", 9.8},
        {"Hero", 6.0},
        {"Strange thing", 9.8},
        {"Chuck", 9.4},
        {"Test 1", 6.7},
        {"Test 2", 7.5},
        {"Test 3", 3.2},
        {"Test 4", 8.0},
        {"Test 5", 0.0},
        {"Test 6", 0.0}
    };

    set<string> results;
    vector<pair<string, float> > allMoviesV;

    transform(allMovies.begin(), allMovies.end(), back_inserter(allMoviesV), [](map<string, float>::iterator i) -> pair<string, float> {return *i;});
    if (allMovies.size() <= 10) {
        transform(allMoviesV.begin(), allMoviesV.end(), inserter(results, results.end()), [](vector<pair<string, float> >::iterator i)->string {return i->first;});
    } else {
        sort(allMovies.begin(), allMovies.end(), compare);
        transform(allMovies.begin(), allMovies.end(), inserter(results, results.end()), [](vector<pair<string, float> >::iterator i)->string {return i->first;});
    }

    // copy(results.begin(), results.end(), ostream_iterator(cout));

    for (set<string>::iterator i = results.begin(); i != results.end(); ++i) {
        cout << *i << endl;
    }

    return 0;
}