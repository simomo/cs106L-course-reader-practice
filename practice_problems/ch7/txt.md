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