# 1. Give three reasons why STL algorithms are preferable over hand-written loops.

1. Everybody know what you are trying to do, once they saw the algorithm.
2. No needs to invent the wheel every time, and it prevents your mistakes.
3. The performance probably is better.

# 2. What does the _if suffix on an STL algorithm indicate? What about _n ?

## `_if`

Do something if some criterions are met.

## `_n`

Do something multiple(n) times.

# 3. What are the five iterator categories?

## Input iterator

`auto a := *iter`
`++iter`

## Output iterator

`*iter = a`
`++iter`

## Forward iterator

`++iter`

## Bi-direction iterator

`++iter`
`--iter`

## Random access iterator

`++iter`
`--iter`
`iter + n`
`iter[n]`

# 4. Can an input iterator be used wherever a forward iterator is expected? That is, if an algorithm requires a forward iterator, is it legal to provide it an input iterator instead? What about the other way around?

It's legal to use a input iterator as a forward iterator, but the reverse is illegal.

# 5. Why do we need back_insert_iterator and the like? That is, what would happen with the STL algorithms if these iterator adaptors didn't exist?

Iterator adaptors are necessary abstrations of STL containers' capabilities, each one represents
a range of containers with some same capabilities. It's essential for algorithms, without them,
what should the type of algorithms's arguments be?

# 6