# Matrices and matrix operations

## Matrices and Vectors

- A matrix is a rectangular array of numbers
- $A^T$ is the `transpose` of the matrix $A$, and it means to exchange the rows and the columns of the matrix
- A `vector` is a matrix with only one dimension
- A `unit vector` is a vector whose magnitude is `1`
- A `zero matrix` is a mtrix whose all elements are `0`

### Square Matrices

- `Square matrices` are matrices of size $n*m$
- A `diagonal matrix` is a matrix that all the items are `0` where $i \neq j$
- A `identity matrix` is a diagonal matrix with all nonzero items equal `1`
  - The $i_{th}$ column of the `identity matrix` is a `unit vector`
- A `tridiagonal matrix` is a matrix with all the nonzero elements appear only when $|i - j| > 1$
- An `upper-tridiagonal matrix` is a matrix with $u_{ij} = 0$  appear when $i \gt j$
- The opposite for `lower-tridiagonal matrix`
- A `permutation matrix` is a matrix where there is a `1` in each row or column, and all other elements are `0`
- A `symetrix matrix` is a matrix where $A = A^T$
