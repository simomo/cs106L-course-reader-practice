# What's the best practice of writing a complex program

Like the "snake", it's very different with the program I used to write, things like web
 application or web pages, those programs are straight-forwad, the hard points are basically
 high performance(handling 10K requests in one seconds) or fancy visiual effects. But "snake"
 is different, it's more complex.

 ## 1. Design the data structure first

 ## 2. Write down the skeleton implemenation

 ## 3. Fulfill each parts

# Return a local `vector` from a function

According to [this](https://stackoverflow.com/a/15704602/807695), in C++, it will returned by value.
```c++
std::vector<string> f() {
    std::vector<string> v;
    return v;
}
```

# Iterate a vector

It will be learned at the next chapter.
```c++
static void PrintVector(vector<string>& values) {
    string oneLine;
    vector<string>::iterator it;
    for (it = values.begin(); it != values.end(); ++it) {
        cout << *it << endl;
    }
}
```