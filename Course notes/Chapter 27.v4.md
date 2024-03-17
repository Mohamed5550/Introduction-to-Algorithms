# Online Algorithms

## Introduction

- In most of the previous chapters, we assumed that the whole input is available before we start the algorithm
- However, this is not always the case, as we saw in Data structures and amortized analysis, we don't know the next operation but we maintain a constant cost per operation
- In online algorithms we try to get an algorithm that works well with any unknown future inputs
- `competitve analysis` is the method of comparing the solution of the onlint algorithms with the optimal solution that is aware of all the input

## Waiting for an elevator

- Suppose you want to go up, you have two options
  - taking the elevator (`1`)
  - using the stairs (`k`)
- but you don't know when the elevator will go down
- you will not do better than a one who knows when the elevator will go down `competitive analysis`
- $competitve ratio = max\{A(I)/F(I): I \in U\}$
  - where $A(I)$ is the time of the online algorithm
  - $F(I)$ is the time of the optimal algorithm
  - and $I$ is any set in the input universe $U$
- if the online algorithm has ratio of `c` we say it is `c-competitve`
- The solution of always taking the stairs gives us `c = K`
- The solution of always taking the elevator gives us `c = B/K`
- The solution of waiting for `k` minutes then using the stairs if the elevator hasn't come gives us `c = 2`

## Maintaining a search list

- If you don't know the numbers that will be searched then the time will be `O(nm)`
- but if you know them, you may add the most searched items in the begining of the list
-
 