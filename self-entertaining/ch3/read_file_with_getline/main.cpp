#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream f("cities.txt");
    if (!f.is_open()) {
        cout << "Open cities.txt failed!" << endl;
        return -1;
    }

    string city, country;
    while (getline(f, city) && getline(f, country)) {
        cout << "The city " << city << " is the capital of " << country << "." << endl;
    }
}