# String Manipulation Preprocessor Functions

*Talk is cheap, show me the code*

```c++
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
```

is converted to

```c++
# 1 "main.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "main.cpp"
# 2 "main.cpp" 2

# 8 "main.cpp"
using namespace std;

int main() {
    cout << "PRINTOUT: " << "87 * 24" << endl;;
    cout << "PRINTOUT: " <<87 * 24 << endl;;
    type_int;
    type_ "int";
    return 0;
}

```

## `#s`

## `##t`


## How to get this?

`gcc -E main.cpp`, it will raise an error, but the result still is generated.