#include <iostream>

#include "grid.h"

int main() {
    Grid<int> g1;
    Grid<int> g2(2, 3);

    fill(g2.begin(), g2.end(), 1);
    // sort(g2.row_begin(0), g2.row_end(0));
    cout << g2[1][1] << endl;

    const Grid<int> g3(2, 3);
    // g3[1][2] = 0;  <-------- Error!

    return 0;
}
