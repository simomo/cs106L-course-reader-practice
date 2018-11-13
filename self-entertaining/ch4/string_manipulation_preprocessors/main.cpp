#include <iostream>

#define PRINTOUT(s) cout << "PRINTOUT: " << #s << endl;
#define PRINTOUTE(s) cout << "PRINTOUT: " << ##s << endl;
#define EXTEND(t) type_##t
#define EXTENDE(t) type_#t

using namespace std;

int main() {
    PRINTOUT(87 * 24);
    PRINTOUTE(87 * 24);
    EXTEND(int);
    EXTENDE(int);
    return 0;
}