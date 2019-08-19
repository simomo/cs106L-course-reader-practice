// 15. Show how to use a combination of copy and iterator adapters to write the contents of an STL
// container to a file, where each element is stored on its own line.
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    vector<string> stage = {"A\n", "B\n"};
    ofstream o("output.txt");
    // ostreambuf_iterator<char> oo(o);  // ostreambuf_iterator vs ostream_iterator
    ostream_iterator<string> oo(o);
    copy(stage.begin(), stage.end(), oo);
    return 0;
}