# Dynamic programming

## Introduction

- Dynamic programming like divide and conquer in dividing the problem to subproblems
- Unlike divide and conquer its subproblems overlap
- Progamming in dynamic programming refers to tabular methods not to writing computer code
- Dynamic programming solves optimization problems
- When developing a dynamic programming solution we follow some steps:
  - construct the structure of optimal solution
  - define the value of the solution in recursive way
  - build the solution in bottom-up manner
  - construct the optimal solution from computed information

## Rod cutting

- Naive solution runs in $2^n$
- Dynamic programming solution lockups the values instead of recalculating them
- time-memory trade-off
- top-down: memiozation
- bottom-up: faster than th top-down because of the constant factors
- subproblem graph: like a reduced recursion tree

## Matrix-chain multiplication

- Two hallmark when dynamic programming applis:
  - the problem has an optimal structure
  - the problem has overlapping subproblems

## Elements of dynamic programming

- Two keys to determine if dynamic programming applies:
  - Optimal substructure
    - The common pattern followed to discover optimal substructure
      - Making a choice
      - You assume that you are given the choice to lead to optimal solution, don't care how.
      - You can determine which subproblems can be built on this optimal choice
      - Cut-and-paste technique
    - The running time of dynamic programming depends on:
      - the number of subproblems overall
      - the number of choices

  - Overlapping

## Longest Common Subsequence

## Optimal binary search trees

- 