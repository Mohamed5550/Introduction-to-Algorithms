# van Emde Boas Trees

## Introduction

- The main goal is to achieve dynamic set operations in O(lglgn)

## Preliminary approaches

- Direct addressing

- Superomising a binary tree
  - minimum
  - maximum
  - successor
  - predecissor
  - all like binary search tree

- Superomising a tree of constant height
  - array of size $sqrt(n)$ called clusters
  - each cluster equals the or of its subtree
  - each cluster containes $sqrrt(n)$ items
  - min, max, suc, pre, all in O(sqrt)
  - insert O(1)

