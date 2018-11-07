# `stringstream`

## Why we need it

One kind of common tasks is that we need to extract data in different types from a string, or output data in different types to a string, `stringstream` is one answer for these tasks.

It provides `>>` and `<<` operators just like the file stream and the io stream.

## Implement `getInt` with `stringstream`

1. `getline` helps us put user input into a string, then we feed it to a `stringstream`.
2. we try to extract a int from the `stringstream`, and handle two kinds of failures:
   1. it can't be extracted out a int
   2. user inputs more unexpected words after a int