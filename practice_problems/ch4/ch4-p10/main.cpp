
#include <iostream>

enum Color {
#define DEFINE_COLOR(color, opposite) eColor_##color,
#include "../ch4-p9/color.h"
#undef DEFINE_COLOR
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
