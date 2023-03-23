# Amortized analysis

## It is for analysis purposes only and shouldn't appear in the code

## Aggregate analysis

- There is a time T(n) for all operations
- There is a time T(n)/n for each operation even if they are different operations
- Stack operations
  - we have operations pop O(1), push O(1), multipop O(n)
  - but wen we use the three together n times on an initially empty stack, the worst case will be O(n) not O(n^2), why? because the numbe of pops, inclusing the pops inside multipop cannot be greater than the total number of pushs
- Incrementing a binary counter

## Accounting method

- You have credit, you spend all the credits at the end of the time, you pay for each amortized time separatelly on its step
- Different operatoins may have different amortized costs
- the total credit of the datastructure must not be nonnegative
- Stack operations
- Incrementing a binary counter

## The potential method

- It represents the prepaid work as potential energy
- stack operations
- incrementing a binary counter
