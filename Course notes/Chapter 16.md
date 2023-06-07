# Greedy Algorithms

## Introduction

- Optimization problems go thgough steps of choosing some items
- DP may be overkill sometimes, so a greedy algorithm will be simpler and faster
- Greedy algorithms doesn't always get the optimal solutions but it does at many problems

## An activity-selection problem

- The DP recurrence of this problem is dp[i][j] = dp[i][k] + dp[k][j] + 1 // for each k between i and j
- The greedy solution always takes the first element of the next subproblem
- Its recusion is tail recustion, it can be easily converted to iterative code

## Elements of the greedy strategy

- Steps
  - Casting optimization problem to be of only one subproblem for each choice
  - Prove that it yields an optimal solution
  - Demonstrating optimal substructure

- Every greedy sollution have a DP solution
- Greedy-choice property:
  - It means that choosing the optimal solution in the current step, leads to the optimal solution for all the problem, this must be proved for each problem
- Optimal substructure property:
  - It means that the final solution of the problem consists of the optimal solution of some subproblems, it works for both DP and Greedy

`