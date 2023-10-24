# Data structures

- Programmable sets are such as mathematica sets
- sets that allows inserting, deleting, checking membership are called dictionaries

## Operatoins on Dynamic sets

- queries: getting data
- modifying: setting and editing data

## Elementary Data structures

- Stack
  - LIFO: last in first out
  - inserting: increasing size and adding new element
  - erasing last element: remove element and decreasing size

- Queue:
  - FIFO: first int first out
  - insert (enqueue): 
  - delete (dequeue):

- Linked list:
  - Objects are arranged in order one by one
  - It can perform all the dynamic set operations (not necessariliy effecient)
  - There are singly and doubly linked lists
  - Searchh is linear
  - Inserts and deletes are in O(1)
  - Sentinels are used to ignore the headace of the list boundaries

## Implementing pointers and objects

- We can store them in 3 arrays, next, prev, value
- we can use only one array, 3 indices for each item

## Representing rooted trees

- We will represent rooted trees using linked lists
- Binary trees can be stored using left and right attributes in the node object
- There is a clever implementation to use only O(n) space, left-child-right-sibling
- DSU representations use another shcema that have only pointer to parent
- There are many other schemas, depending on the application
