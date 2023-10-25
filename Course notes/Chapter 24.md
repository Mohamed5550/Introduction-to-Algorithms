# Chapter 24: Single source shortest paths

## Introduction

    We need to find the shortest path between two nodes in a graph

- W(p) is the sum of all the weights of the path

$\sum_{i=1}^k{w(v_i, v_{i-1})}$

let $δ(u, v)$ be the shortest path from u to v

- **Optimal substructure:** every shortest path constains of other smaller shortest paths inside it
- Every path between any two vertices in the shortest path is also a shortes path between these two vertices

- there is no negative cycles in shortest paths because it will be $-∞$
- there is no positive cycles also, because we can remove an edge with the same source and destination

## Representing shortest paths

- we represent them by assigning the parent for each vertix

## Relaxation

- We maintain $v.d$ which is a shortest path estimate
- Relaxation checks if we can improve the current shortest path of a vertix
- All algorithms in the chapter use the relaxation technique

## Propertes of shortest paths and relaxation

- **Traingle inequality:**

    For any edge $(u, v)$, $δ(s, v) \le δ(s, u) + w(u, v)$

- **Upper-bound property:**

    We have that $v.d \ge δ(s, v)$, and when it achieves $δ(s, v)$, it never changes again

- **No-path property:**

    If there is no path, then $v.d = δ(s, v) = ∞$

- **Convergence property:**

    If $s \ to \ u \rarr v$ is a shortest path in $G$, then when $u.d = δ(s, u)$ before the relaxation of $(u, v)$, then $v.d = δ(s, v)$ this relaxation
