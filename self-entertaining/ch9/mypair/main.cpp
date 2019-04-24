#include <string>

using namespace std;

template <typename firstType, typename secondType> struct MyPair {
    firstType first;
    secondType second;
};

MyPair<int, string> mp;

template <typename firstType, typename secondType> class MyPair1 {
public:
    firstType getFirst() {
        return first;
    }
    void setFirst(firstType f) {
        first = f;
    }

    secondType getSecond();
    void setSecond(secondType s);

private:
    firstType first;
    secondType second;
};

template <typename firstType, typename secondType>
secondType MyPair1<firstType, secondType>::getSecond() {
    return second;
}

template <typename firstType, typename secondType>
void MyPair1<firstType, secondType>::setSecond(secondType s) {
    second = s;
}

int main () {
    mp.first = 0;
    mp.second = "aaa";
}