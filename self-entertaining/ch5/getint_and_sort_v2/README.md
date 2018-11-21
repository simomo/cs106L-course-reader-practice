# `getline(cin, aStringStream)` is not correct!

It must be `getline(cin, aString)`.

# What's v2 improved?

Saving user input and sorting are at the same time.

# Notice the function parameters: by references? Or values?

Just don't pass parameters by values rectlessly. Think.

# Don't be afraid

Don't be afraid of thinking complex questions, it's totally OK that we don't have a clear vision of the solution immediatly. Give youself more time to figure it out. What's the standard of "I've figured it out"? Here are examples:

## Example 1

    1. Find the smallest element of the vector and put it in position 0.
    2. Find the smallest element of the remainder of the vector and put it in position 1.
    3. Find the smallest element of the remainder of the vector and put it in position 2.

## Example 2

    we need to answer two
    questions. First, how do we find out where in the vector the user's element should go? Second, how do
    we insert an element into a vector directly at that position? This first question is algorithmic; the second
    is simply a question of what operations are legal on the vector . 