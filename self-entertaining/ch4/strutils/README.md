# How to compiling

This is a mini example for demostrating what a multiple files c++ program looks like, compiling: `g++ *.cpp`

# `converter.str()`

Comparing to `DoubleToString`, `IntToString` is cleaner, `converter.str()` can replace the pattern below:

```c++
string output;
stringstream converter;

converter >> output;
```

# A bug caused by un-intialized size_t

The first version of `ConvertToLower` is:

```c++
string ConvertToLowerCase(string input) {
    for (size_t i; i < input.size(); ++i) {
        input[i] = tolower(input[i]);
        cout << input[i] << endl;
    }

    cout << input << endl;
    return input;
}
```

It will return the input as it is passed in(all upper characters), why?
The root cause is `size_t i` is un-intialized, I print it out, it's a huge number...  
***Don't forget initialize your size_t!***