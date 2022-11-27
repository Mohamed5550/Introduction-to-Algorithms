# Red-Black Trees

- ## Properties of red-black trees

  - Every node is either red or black
  - The root is black
  - Every leaf (NULL) is black
  - if a node is red, then both of its children are black
  - For each node, all simple paths from the node to descendant leaves, contains the same number of black nodes
  - The ***black-height*** is the path from a node down to a leaf (not including the node)

- ## Rotations

  - We rotate left by getting the right child in place of the parent, then transform then update the left, right and parent of both nodes to make the tree a correct BST.
  - the right rotation is symetric

- ## Insertion

test
