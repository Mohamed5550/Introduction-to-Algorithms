# Chapter 23: Minimum Spanning Trees

## Introduction

- Spanning trees are a tree that connects all the graph with n-1 edges
- We need to find the minimum one in cost

## Growing a minimum spanning tree

- The general method is to keep adding safe edges until the subset is a minimmum spanning tree
- A is the growing minimmum spanning tree
- A cut is a partition of E
- A cut respects A when there is no edges crosses the cut
- a light-edge is the minium edge crossing the cut

## The algorithms of Kurskal and Prim

- Kruskal algorithm sorts the graph by edges weights, then it union them if they are ins different unions one by one in order
- It depens directly on Corrollary 23.2
