//
//  main.cpp
//  ch3-p5
//
//  Created by duozhang on 17/12/19.
//  Copyright © 2017年 duozhang. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;

string int2string(int i) {
    stringstream converter;
    string ret;
    converter << i;
    converter >> ret;
    return ret;
}

int main(int argc, const char * argv[]) {
    string a = int2string(100);
    if (a != "100") {
        cout << "failed" << endl;
    } else {
        cout << "success!" << endl;
    }
}
