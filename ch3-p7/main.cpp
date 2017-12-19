//
//  main.cpp
//  ch3-p7
//
//  Created by duozhang on 17/12/19.
//  Copyright © 2017年 duozhang. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
using namespace std;


// get one line from stdin
string GetLine() {
    string ret;
    getline(cin, ret, '\n');
    cout << "Got: " << ret << endl;
    return ret;
}

// extract a int
void get_bool() {
    string ret;
    
    while (true) {
        stringstream converter;
        converter << GetLine();
        if (converter >> ret && (ret == "true" || ret == "false")) {
            char remains;
            if (converter >> remains) {
                cout << "Unexpected character: " << remains << endl;
            } else {
                bool r;
                if (ret == "true") {
                    r = true;
                } else {
                    r = false;
                }
                cout << boolalpha << r << endl;
            }
            
        } else {
            cout << "converter fail: " << boolalpha << converter.fail() << endl;
            cout << "Please enter 'true' or 'false' ret: " << ret << endl;
        }
        
    }
}

int main(int argc, const char * argv[]) {
    get_bool();
}