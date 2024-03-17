# Chapter 29: Linear Programing

If you have some objectives that can be represented as linear functions and there are constraints on these objectives that can be represented as equalities or inequalities, then we are in front of a linear programming problem

## A political problem

- You have elections and you need half of the regisered votes in each area to win
- Each area will vote for some election programm of yours
- You need to win the elections with the minimum number of money spent on advertising
- You can find the answer by trial and error
- But a better way is to model it mathematically

### Mathematical model

- First you have 4 dicisions, then there are 4 `decision variables` {x1, x2, x3, x4}
- Each variable represents the number of thousand dollars spend on a specific advertising program
- Then yo think about `constraints` on these variables, to get a feasible solution
- Finally you think about the `objective`, which mean the think you want to minimize or maximize, which here is `x1+x2+x3+x4`
- Then we have to set a nonnegative constraint to prevent negative money spent $x1 \ge 0, x2 \ge 0, x3 \ge 0, x4 \ge 0$
- Combining all these formals is known a `linear program`
- The solution to this linear program yields to the optimal strategy

## Linear programming formulaions and algorithms

### General linear programs

- Given a set of real numbers `a1, a2, a3,...an` and a set of variables `x1, x2, x3,...xn`, we define a linear function `f` by
- $f(x_1, x_2, x_3,...x_n) = a_1x_1+a_2x_2+a_3x_3+....+a_nx_n = \sum_{j=i}^{n}{a_ix_i}$
- We use the term `linear constrains` to denote either a linear equality or a linear inequality
- Linear programs doesn't allow strict inequalities
- Formally, a linear programming problem is maximizing or minimizing a linear function subject to a finite number of `linear constraints`

### solving the linear program

- If we have a solution that satisfies the `linear constraints`, then it is a feasible soution, when the feasible solution satisfies the `objective function`, then it is an optimal solution
- If the linear program has a set of feasible solutions but doesn't have an optimal solution, then the feasible region `unbounded`
- One of the reasons for the powe and popularity of linear programming is that it can, in general be solved effeciently
- There are two classes of algorithms to solve linear programs in polynomial time
  - Ellipsoid algorithms
  - Interior-point algorithms
- The `simplex` algorithm is widely used but it is not polynomial time in worst case, but it has a good time in practice

### A two-variable linear program

- Suppose we have a linear program with only 2 `decision variables`
- We can graph it in a 2D cartesian plane
- The feasible area is the area that achieves all the constraint
- Then we draw a line for the objective function and intersect it with the feasible area
- We then get the max value of the intersection between the `feasible plane` and the `objective line`
- The same holds for n `objective variables`
- The feasible region is called the simplex
- The `simplex` algorithm iterates like the `Ford Fulkerson` method, that every iteration has a larger value than the previous one
- It terminates when it reaces a local maximum. We then prove that the local maximum is a global maximum with the `duality`
- The `simplex` algorithm is not polynomial in worst case but it is fast in practice
- The `ellipsiod` algorithm is polynomial but it is slower than the `simplex` algorithm in practice
- The `interior-point` algorithm can beat the `simplex` algorithm for large inputs

## Formulating problems as linear programs

- There are somg graph problems that can be formulated is a linear program

### Shortest paths

- To formulate the shortest path problem we set the `decission variables` to $d_t$ and the `linear constraints` to the trangular inequality of shortest paths $d_t \le d_u + w(u, v)$

  maximize $d_t$

  subject to
    $d_v \le d_u + w(u, v)$ for each edge $(u, v)$

- Why maximizing while we are finding the shortest path?
  - Because minimizing it will always give `0` as a feasible solution, so maximum feasible one is the optimal shortest path

### Maximum flow

- It is easy, we will just formulate the maximum flow conditions

  maximize $\sum_{v \in V}{f_{sv}} - \sum_{v \in V}{f_{vs}}$
  
    subject to
    $f_{vu} <= c_{vu}$ for each $v, u$ in $V$

    $\sum_{v \in V}{f_{vu}} = \sum_{v \in V}{f_{uv}}$ for each $u$ in $V$

    $f_{vu} \ge 0$ for each $u, v$ in $V$

### Minimum-cost flow

- We have seen linear programming solution for problem that we had other more efficient algorithms for
- But the power of linear programming that it solves problems that we don't have an efficient solution for
- It has the same formulation of the max flow but it contains additional constrains for the demand the cost

### Multicomodoty flow

- It is the same but there are mult comodoties not only one

## Duality

- Duality is more general than linear programming but will examine it here in liner programming
- Duality means that the problem of maximization has a minimization problem that have the same objective value
- Like the max flow it has a min cut problem
- We call the original linear program a `primal`
