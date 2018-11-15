# `enum` defination

```c++
enum { A, B, };
```

# `switch()` only accepts int

```c++
switch(aString) <------------- X error
```

# `enum` value can be accepted by `switch()`

```c++
switch(A)
```

# String to enum

```c++
LengthUnit SuffixStringToLengthUnit(string suffix) {
    #define DEFINE_UNIT(unit_name, value, symbol, system) if (suffix == #symbol) return eLengthUnit_##symbol;
    #include "units.h"
    #undef DEFINE_UNIT

    return eLengthUnit_ERROR;
}
```