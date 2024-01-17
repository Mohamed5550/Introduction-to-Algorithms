# Parallel Algorithms

## Introduction to Selected Topics

- The selected topics are more advanced topics based on the previous book chapters

## Introduction to parallel algorithms

- All the previous algorithms are serial, which means they work on single processor
- Our study in this chapter focuses on fork-join, which is the most basic kind of task-parallel algorithms
- All computers are multi-cores, which means they have multi processors
- One approach is to use the threads, but its programming is difficult

### Task-parallel programming

- The difficulty of thread programming led to the creation of task-parallel platforms
- This means to make a layer on top of the threads to coordinate, schedult and manage the processors of a multicores

### Fork-join parallelism

- although the functionality is still evolving, almost all environments support fork-join parallelism
- Advantages of Fork-Join:
  - the fork-join is simple extension of the serial programming, so we need to add only 3 keywords to any pseudocode and it will be converted to fork-join which are: `parallel`, `spawn`, `sync`
  - Spawning allows many divide-and-conquer algorithms to run effeciently

## The basics of Fork-join parallelism

- Our exploration of parallel programming begins with Fibonacci series
- Finding Fibonacci number recursivly runs in $O(Fn)$
- We can compute each of the two $F_{n-1}$ and $F_{n-2}$ parallely because one's value doesn't affect the other

### Parallel keywords

- `spawn`: means not to wait for the subroutine and continue the next steps
- `sync`: means to wait here for the spawn subroutine to finish

### A graph model for parallel execution

- The dircted asyclec graph called a `(parallel) trace`
- The vertices are the instructions
- The directed edge (u, v) means instruction v must run before u
- if `G` contains a directed edge between `u` and `v` then it is logically in series
- if not, it is logically in parallel
- the `load instruction` copies the data from memory to processor register
- the `store instruction` copies the data from processor register to memory

### Performance measures

- work law: $T_p \ge T_1 / p$
- spawn law: $T_p \ge \infty$
- speedup: $T_1 / T_p \le P$ is is perfect speedup when $T_1 / T_p = P$

### Scheduling

### Parallel loops

- `parallel` keyword is used when there is a for loop which its iterations can run in parallel

### Race conditions

- when the loop uses a variable that changes in every iteration, then parallelizing it makes race conditions

### A chess lesson

## Parallel matrix multiplication

- 