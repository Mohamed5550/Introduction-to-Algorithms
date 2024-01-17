# Maximum Flow

## Introduction

- Imagine a directed network like water pipes
- There must be a source, and there must be a sink
- The amount of liquid leaving the source at any point of time must equal time amount of liquid entering the sink. It is equivalent to kirchhof's law if the liquid is electricity
- Our goal in this chapter is to find the max rate that we can pass from the source to the sink through the network

## Flow networks

- We will give graph definition of the max flow problem then define it precisely

### Flow networks and flows

- a flow network $G = (V, E)$
- each edge $(u, v) \in E$ has a non-negative capacity $c(u, v) \ge 0$
- if $(u, v) \in E$ then it has no reversed edge
- there are no self-loops
- source is $s$ and sink is $t$
- each vertix is between $s$ and $t$
- flow between $u$ and $v$ is $f(u, v) \le c(u, v)$
- for all u \notin \{s, t\} $$\sum_{v \in V}f(v,u) = \sum_{v \in V}f(u,v)$$
 which means all flow leavin a vertix equals all flow entering it
- formally, "flow in equals flow out"

### Anti-parallel edges

- To convert a graph containing anti-parallel edges to equivalent one with no anti-parallel edges just choose one of the edges and split it by adding a vertix in the middle

### Network with multiple sources and sinks

- To convert it to a single source and sing sink, just add a supersource connected to all the sources and a supersink connected to all the sinks with capacity of $\infty$

## The Ford-Fulkerson method

- we initialize the flow to 0
- we repeatedly augnent the flow until the residual network has no more augmenting paths

### residual networks

- Residual networks $G_f$ are the edges that have remaining flow in the original graph $G$

### Augmenting paths

- $|f↑f_p| = |f| + |f_p| > |f|$
- which means when we agument a networks with its agumenting path its flow becomes greater

### Cuts of flow networks

- how do we know that when Ford-Fulkerson terminates, we will have the maximu flow?
- a cut $(S, T)$ is like the cut we used in minimum spanning trees but here they are directed
- the net flow across the cut equals $$\sum_{u \in S}\sum_{v \in T} f(u, v) - \sum_{u \in S}\sum_{v \in T} f(v, u)$$
- the capacity equals: $$\sum_{u \in S}\sum_{v \in T} c(u, v)$$
- a ***minimum cut*** is a cut whose capacity is the minium between all cuts
- We have that the maximum flow $|f| = f(S,T)$ for any cut $(S, T)$
- The maximum flow $|f| = f(S,T) \le c(S, T)$ for all cuts
- which means the maximum flor $|f| \le$ the capacity of the minimum cut
- There is a prove that the maximum flow $|f| = c(S, T)$ for the minimum cut

## Edmonds-Karp algorithm

- When we choose the augmentation path to be the shortes path in the residual network, the bounds become $O(VE^2)$

## Bipartite Matching

- We can add a source and a sink like we did in the multi-source multi-sink problem to solve the max-bipartite matching as a max-flow problem
