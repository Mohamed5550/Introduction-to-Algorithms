# Polynomials and FFT

You can sum two polynomials of degree `n` n $O(n)$, but you multiply them in $O(n^2)$

With Fast Forier transform we will multiply them in $(Olgn)$

## Polynomials

- polynomial of degree $n$ is a polynomial with max power of $n$
- polynomail of degree $n$ has `degree-bound` of any interger greater than $n$
- In `polynomial summation` we sum terms with the same powers together
- in `polynomial multipying` the bound of $n$ becomes $2n-1$

## Representing polynomials

### Polynomial representation

- To evaluate a polynomial in $O(n)$ time we use `Horner's Rule`
- $A(x) = ((a_nx+a_{n-1}x)+a_{n-2}x...)a_0x+x$
- summing will take $O(n)$ in polynomail form, and multiplying takes $O(n^2)

### Point-value representation

- A point-value represenation of a polynomial of degree-bound $n$ is a set of $n$ point-value pairs from $0$ to $n-1$
- The inverse form of evaluation a coefficient form from a point-value form is called `interpolation`
- To add two polynomials of degree $n$ we use
  - $C(x) = \{(x_0, y_0+y^`_0), (x_1, y_1+y^`_1), ...\}$
  - Thus, addition time is $O(lgn)$
- To multiply two polynomials of degree $n$ we use
  - $C(x) = \{(x_0, y_0.y^`_0), (x_1, y_1.y^`_1), ...\}$
  - Thus, multipluing time is also $O(lgn)$
  - It will get $n$ pairs, but we need $2n$, so we extend $A$ and $B$ to contain $2n$ pairs
- So, can we multiplicate in the coefficient form in $O(n)$ time? It depends on if we can transoform between the two forms fast
- With `FFT` we can evaulate and interpolate the polynomial in $O(nlgn)$ time

## The DFT and FFT

- the complext root of unity is a complex number $ω$ where $ω^n = 1$
- the $n$ roots are $ω_n = e^{2\pi ik/n}$
- In FFT we depend on this formula
$$A(x) = Aeven(x^2) + Aodd(x^2)$$

## FFT Circuits
