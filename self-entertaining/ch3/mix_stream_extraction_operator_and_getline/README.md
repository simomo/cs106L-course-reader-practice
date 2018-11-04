# Don't mix the `getline` function with `>>`

The stream reading operator, `>>`, will skip the newline character, `\n`, and read/extract the meaningful data. While the `getline` function doesn't do so.

So, if you mix them togother, `>>` firstly extracting the first line, and leave the newline character of the first line at where it is; `getline` will meet the newline character before reading the 2nd line, then it will return a empty string.

Solution: Don't mix them together, always use the `getline`.