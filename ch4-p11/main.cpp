#include <iostream>

enum Color {
#include "color.h"  // <---- this will cause #error take effective
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
