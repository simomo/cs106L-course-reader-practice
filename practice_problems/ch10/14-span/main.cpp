#include <vector>
#include <iostream>

using namespace std;


struct Span {
    int start, stop;
};

template <typename ElemType> class Vector {
public:
    Vector(int sizeHint = 0);
    int size();
    bool isEmpty();

    ElemType getAt(int index);
    void setAt(int index, ElemType value);

    ElemType& operator[](int index);
    pair<Iterator, Iterator> operator[] (const Span&) const;

    void add(ElemType elem);
    void insertAt(int index, ElemType elem);
    void removeAt(int index);
    void clear();
    void mapAll(void fn(ElemType elem));
    template <typename ClientDataType>
    void mapAll(void fn(ElemType elem, ClientDataType & data),
    ClientDataType & data);
    Iterator iterator();
};

int main() {
    vector<int> v1(10, 1);
    vector<int> v2(v1.begin() + 2, v1.begin() + 5);  // *Copy* part of v1 to v2
    v2[0] = 2;

    for (vector<int>::iterator i = v1.begin(); i != v1.end(); ++i) {
        cout << *i << endl;
    }

    cout << endl;

    for (vector<int>::iterator i = v2.begin(); i != v2.end(); ++i) {
        cout << *i << endl;
    }
    return 0;
}