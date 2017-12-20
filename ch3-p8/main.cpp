//
//  main.cpp
//  ch3-p8
//
//  Created on 17/12/19.
//

#include <iostream>
#include <sstream>
using namespace std;

bool has_hex_letter(int i) {
    stringstream c1;
    c1 << hex << i;
    
    string i_hex_string;
    c1 >> i_hex_string;
    cout << "i_hex_string: " << i_hex_string << endl;
    
    stringstream c2;
    c2 << i_hex_string;
    int fake_i;
    c2 >> fake_i;
    
    return c2.fail();
}

int main(int argc, const char * argv[]) {
    bool r = has_hex_letter(10);
    cout << "r: " << r << endl;
    r = has_hex_letter(8);
    cout << "r: " << r << endl;
}
