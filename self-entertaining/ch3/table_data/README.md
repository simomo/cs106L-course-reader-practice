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
