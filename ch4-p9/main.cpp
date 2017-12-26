//
//  main.cpp
//  ch4-p9
//
//  Created on 17/12/26.
//  Copyright © 2017年. All rights reserved.
//

#include <iostream>
//#include "main.h"

using namespace std;

enum Color {
#define DEFINE_COLOR(color, opposite) color,
#include "color.h"
    DEFINE_COLOR(NOT_A_COLOR, NOT_A_COLOR)
#undef DEFINE_COLOR
};


Color String2Color(string color_in_str) {
#define DEFINE_COLOR(color, opposite) if (color_in_str == #color) return color;
#include "color.h"
#undef DEFINE_COLOR
    return NOT_A_COLOR;
}

int main(int argc, const char * argv[]) {
    Color r1 = String2Color("Red");
    Color r2 = String2Color("balala");
    std::cout << "r1: " << r1 << " r2: " << r2 << endl;
    return 0;
}
