# setfill will work until another setfill changes it

# const is better than macro

const char * const p

# stream operations may fail

Exacting values from a stream may fail, it can be detected by `.fail()`.
```
ifstream s("somefile");
int v;
s >> v;
if (s.fail()) {
	// do something
}
```

And there is a useful shorthand, exacting and checking can be combined in a if-condition:
```
ifstream s("somefile");
int v;

if (s >> v) {
}
```

# Use `.clear` to recover the stream status

No examples now

# Include the header file `fstream` for `ifstream` and `ofstream`

`#include <iostream>` can also give you the declaration of `ifstream` and `ofstream`, but compiler will raise error while compiling:
`error: variable 'std::ifstream ' has initializer but incomplete type`

It's kind of `forward declaration`. By `incomplete type`, it means the class has not been defined with a full class. The compiler has seen statements such as class `ifstream`; which allow it to understand that a class exists, but does not know how much memory  the class takes up[1]

To eliminate this error, you should `#include <fstream>` too.


[1]: https://stackoverflow.com/a/32654464/807695