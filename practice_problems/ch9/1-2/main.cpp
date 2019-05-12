#include <string>
#include <iostream>

#include "mymap.h"

int main() {
    MyMap<int, string> mm1;
    const MyMap<int, int> mm2(1, 2);

    cout << mm2.find(1)->second << endl;
    cout << mm2.find(2)->second << endl;
    cout << mm2._map.end()->second << endl;

    return 0;
}