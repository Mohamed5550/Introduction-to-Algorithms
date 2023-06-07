# Greedy Algorithms

## Introduction

- Optimization problems go thgough steps of choosing some items
- DP may be overkill sometimes, so a greedy algorithm will be simpler and faster
- Greedy algorithms doesn't always get the optimal solutions but it does at many problems

## An activity-selection problem

- The DP recurrence of this problem is dp[i][j] = dp[i][k] + dp[k][j] + 1 // for each k between i and j
- The greedy solution always takes the first element of the next subproblem
- Its recusion is tail recustion, it can be easily converted to iterative code
