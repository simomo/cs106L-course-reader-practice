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