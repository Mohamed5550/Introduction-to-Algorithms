# Number-Theoritic Algorithms

## Elementary number-theoritic notations

- Divisibility and divisors
  - $d \mid a$ means `d divides a`
  - Every interger divides 0
  - if $d \mid a$ and $a > 0$, then $|d| <= |a|$
  - $d \nmid a$ means `d doesn't divide a`
  - $d \mid a$ if and only if $-d \mid a$
  - every ineger $a$ has trivial divisors $a$ nd $1$
  - non-trivial divisors are known as factors of $a$

- Prime and composite numbers
  - a `prime` number has only two divisors, $1$ and itself
  - a `composite` number has other divisors than the trivial divisors
  - 1, 0, and the negative numbers are not composite nor primes

- Common divisors and greatest common divisors
  - if $d \mid a$ and $d \mid b$, then $d \mid (a+b)$ and $d \mid (a-b)$
  - more generally if $d \mid a$ and $d \mid b$, then $d \mid (ax + by)$
  - greatest common divisor is denoted as `gcd(a, b)`
    - $gcd(a, b) = gcd(b, a)$
    - $gcd(a, b) = gcd(-a, b)$
    - $gcd(a, b) = gcd(|a|, |b|)$
    - $gcd(a, 0) = |a|$
    - $gcd(a, ka) = |a|$
    - $gcd(a, b) = $ the smallest positive linear combinaion of $a, b$
    - if $d \mid a, d \mid b$, then $d \mid gcd(a, b)$
    - $gcd(an, bn) = ngcd(a, b)$

- Relatively prime integers
  - if $gcd(a, b) = 1$, then they are relatively prime
  - if $a$ and $p$ are relatively prime and $c$ and $p$ are relatively prime, then their product is relatively prime with $p$

- Unique prime factorization
  - every number has a unique pdoruct of primes

## Greatest common divisor

- $gcd(a, b) | gcd(b, a\%b)$ and $gcd(b, a\%b) | gcd(a, b)$
- $gcd(a, b) = gcd(b, a\%b)$

- Euclid's algorithm
  - recursive from the last theorem
- Extended Euclid's algorithm
  - returns the linear combination of the $gcd(a, b)$
  - $d = d'$
  - $x = y'$
  - $y = x' - \lfloor a/b \rfloor * y'$

## Modular arithmatic

- Finite groups properties, suppose the operation is *
  - **Colsure:** $a * b \in S$
  - **Identity:** $a * e = e * a = a$ 
  - **Associativity:** $a * (b * c) = (a * b) * c$
  - **Inverse:** $I * a = a * I = e => (Identity)$
- Addition, subtraction and multiplication are easy to deal with in modular arethmatic
- But Division is more complicated
- We multiply by the modular multiplicative inverse instead of dividing
- `modinv(a, m)` = `x` returned from `gcdextended(a, m)`, when the gcd is `1`

## Solving modular linear equations

- $ax = b (mod) n$ is solvable only if $gcd(a, n) \mid b$

## The chinease remainder theorem

## Powers of an element

- 
