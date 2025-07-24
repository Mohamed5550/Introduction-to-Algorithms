# String Matching

## Indtroduction

What is the problem of string matching?

- The problem is to find how many substrings of the big string $T$ matches the small string $P$, or in other words, to find the number of valid shifts

## The Naive Algorithm

This algorithm iterates over the string $T$ and checks if every substring with length $m$ matching the string $P$

This takes time $O(nm)$

## The Rabin-Karp-Algorithm

This algorithm depends on dealing with the substrings as arethmatic numbers, then we can add the next character and remove the previous character then match the equivalent number of the substring from $T$ with the number from the string $P$, this takes $O(n)$ + $O(m)$ for preprocessing

But for large substrings that don't fit in arethmatic memory, we can use modulo which excludes large amount of numbers that don't match the same module of the string $P$

## String Matching With Finite Automata

- We build the automaton from the pattern, where each state represents a correct path from the string to a specific position
- When we reach state $m$, then we got a matching
- Computing the transition function $\delta$ takes $O(m^3*26)$
- It can be improved to $O(n)$ by depending on the $\Pi$ function
- String matching takes $O(n)$

## The Knuth-Morris-Pratt Algorithm

- Here we avoid calculating the $\delta$ function at all
- Instead, we calculate the $\Pi$ function, which holds the shift data for the pattern to match with itself
- The preprocessing time is $O(n)$ by amortized analysis
- The matching time is $O(n)$ by amortized analysis too
