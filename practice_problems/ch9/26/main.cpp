#include <iostream>

using namespace std;

class UniquelyIdentified {
public:
    UniquelyIdentified();

    int getId();

private:
    static int globalId;
    
    int id;
};

int UniquelyIdentified::globalId = 0;

UniquelyIdentified::UniquelyIdentified() : id(globalId + 1) {
    globalId += 1;
}

int UniquelyIdentified::getId() {
    return id;
}

int main () {
    UniquelyIdentified u1;
    UniquelyIdentified u2;
    UniquelyIdentified u3;
    UniquelyIdentified u4;
    cout << u1.getId() << u2.getId() << u3.getId() << u4.getId() << endl;
    return 0;
}