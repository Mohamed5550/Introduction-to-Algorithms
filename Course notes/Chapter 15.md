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
