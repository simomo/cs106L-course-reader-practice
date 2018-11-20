# `#include <vector>` for vector

# `push_back` in STL == `append` in python

```c++
    vector<int> values;

    for (int i = 0; i < numOfInt; ++i) {
        values.push_back(GetInt());
    }
```

# How to clean a stringstream?

```c++
static void CleanSStream(stringstream& ss) {
    ss.str("");  // empty the contents
    ss.clear();  // clear the error flag
}
```
Reference:
* https://stackoverflow.com/questions/2848087/how-to-clear-stringstream
* https://stackoverflow.com/questions/20731/how-do-you-clear-a-stringstream-variable

# The selection sort

## Algorithm

1. Find the smallest element of the vector and put it in position 0.
2. Find the smallest element of the remainder of the vector and put it in position 1.
3. Find the smallest element of the remainder of the vector and put it in position 2.

## My notes

`swapInts` is inspiring.