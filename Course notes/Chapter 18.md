# B-Trees

## Data structures on secondary storage

- RAM access is 100000 times faster than disk drive access
- B-Tree works like RB-Tree but it stores many nodes in each level
- Each node has a key x, then it has x+1 nodes

## Difinition of B-Trees

- A B-Tree T is a rooted tree at T.root having these properties:
  - each node x has these properties:
    - x.n: the number of keys stored in x
    - the keys are stored in a sorted order
    - x.leaf: boolean to check if it is a leaf

  - each node has x.n+1 pointers to its children
  - each key >= its children and <= its right key and his children
  - All leaves have the same depth
  - each node has lower and upper bound to keys it can store

### The height of a B-Tree

## Basic operations on B-trees

### Searching

- Searching a B-tree is like searing on binary search trees
- but we make an (x.n+1) dicission insteaf of two

### Creating an empty tree

### Inserting a key into a B-tree

- It's more compllicated than red-black insert
- We split the keys into t-1
- Then we promote the median key
- We may repeat the splitting process many times upwards until we reach the root
- Splitting:
  - just a bunch of copy-paste operations to splits the node into two nodes
- Inserting