#ifndef GROCERY_H
#define GROCERY_H
#include <string>
#include <map>
#include <cassert>

using namespace std;

class GroceryList {
public:
    GroceryList();
    void addItem(string quantity, string item);
    void removeItem(string item);
    string itemQuantity(string item);
    bool itemExists(string item);
private:
    map<string, string> theList;
};
#endif
