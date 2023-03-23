# Divide and Conquer

- Divide: the problem into smaller subproblems
- Conquer: the subproblems by solving them recuresivley
- Combine: the solved subroblems into the original problem

The first state is called the recusive case, and the smallest state is called the base case when the recursion "bottoms out"

## Threre are three methods for solving recurrence

- Substitution method: we guess a bound and use mathematical induction to prove it.
- Recursion-tree method: converts the recurrence into nodes whose values are the cost at the levels of the recurision
- Master method: provides bounds for recurrence of the form: T(n) = aT(n/b) + f(n) // a >= 1, b > 1


## Technicalities in recurrence

- We ignore the boundry conditions represent another class of the problem
- We ignore floors, ceiling and rounds

## The maximum subaray problem

- brute force: checking every pair O(n^2)
- divide and conquer:
    = at every level the max subarray-sum is one of three:
        -- the max of the right
        -- the max of the left
        -- the max crossing right and left

## Strassen's method for multipying matrices: Skipped for now

## Substitution method:

- Guess the form
- Use mathematical induction to prove it

- Changing variable method for simplificaiton, like setting S(m) = T(2^m)

## Tree method

## Master method
