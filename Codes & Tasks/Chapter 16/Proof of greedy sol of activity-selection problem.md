# Proof

## Proof that the first item is included in a max-set

All the numbers are sorted by the finish time
Let S be the set of all activities, and K be is a set with maximum mutually compatible activites

Let the first element of K is a, and the first number in S is b.

Now we want to prove that $K - a\ \cup b$ is a max-set
We know that a has a finishing time less than b, because a is the first element in the set.

let c be the second element of K
K will still consists of disjoint sets while `fa < fc`
But `fb < fc` and `fa < fb`

then `fa < fc`.

Proof completed
