#ifndef MYMAP
#define MYMAP

#include <map>

using namespace std;

// A map with a self-defined max number for its entities
template <typename K, typename V>
class MyMap {
public:
    MyMap();
    MyMap(K k, V v);

    typename map<K, V>::const_iterator find(const K k) const;
    int giveMeTen() const;

// private:
    map<K, V> _map;
    int maxNum;
    const static int defaultMaxNum = 100;
};

template <typename K, typename V>
MyMap<K, V>::MyMap():maxNum(defaultMaxNum) {}

template <typename K, typename V>
MyMap<K, V>::MyMap(K k, V v):maxNum(defaultMaxNum) {
    _map[k] = v;
}

template <typename K, typename V>
typename map<K, V>::const_iterator MyMap<K, V>::find(K k) const {
    return _map.find(k);
}

template <typename K, typename V>
int MyMap<K, V>::giveMeTen() const {
    return 10;
}

#endif