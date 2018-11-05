# An example of reading file with `getline`

The solution is very like the one in [fileio_error_handling](https://github.com/simomo/cs106L-course-reader-practice/blob/master/self-entertaining/ch3/fileio_error_handling/fileio_error_handling.cpp)

Two checks is strong enough for file reading.
```c++
if (!fStream.is_open()) {  // 1st Checking

}

while (getline(fStream, stringA) && getline(fStream, stringB)) {  // 2nd Checking

}
```