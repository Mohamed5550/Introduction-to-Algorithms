# Data structures for Disjoint Sets

- most dsu applications perform two operations:
  - finding the set containing an element
  - grouping two sets

## Disjoint-set operation

- makeSet(): of only one element
- SetsUnion(): grouping two sets into one set
- FindSet(): finding the set which contains this element

### An application of disjoint-set data structure

- Connected components

## Linked list representation of disjoint sets

- A head pointing to the first item in the set
- doubly linked list containing the remaining elements
- This takes O(n^2) time
- If we put the smaller one into the larger one, the time will decrease to O(m+nlgn)

## Disjoin-set forests

- Tree representation of a djsoint set
  - make: creates one node
  - find set: goes up until reaching parent
  - union: making first head point to second head

### Union by rank

- We set a rank (equal to height) to each set
- We link the smaller head to the larger one

### Path compression

- When we use find: we update the paths to point to the root directly
