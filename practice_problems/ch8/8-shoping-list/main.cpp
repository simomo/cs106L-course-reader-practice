#include "grocery.h"

void GroceryList::addItem(string q, string i) {
    theList[q] = i;
}

void GroceryList::removeItem(string item) {
    theList.erase(item);
}

string GroceryList::itemQuantity(string item) {
    assert(theList.find(item) != theList.end());
    return theList[item];
}

bool GroceryList::itemExists(string item) {
    return theList.find(item) != theList.end();
}

int main() {

    return 0;
}