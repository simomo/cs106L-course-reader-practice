// 14. Show how to use a combination of copy , istreambuf_iterator , and ostreambuf_iterator to
// open a file and print its contents to cout .
#include <algorithm>
#include <iterator>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream i("main.cpp");
    istreambuf_iterator<char> ii(i);
    ostreambuf_iterator<char> oo(cout);
    copy(ii, istreambuf_iterator<char>(), oo);
    return 0;
}