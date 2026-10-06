# 33.1-2

Give an example in the plane with $n = 4$ points and $k = 2$ clusters where an iteration of Lloyd’s procedure does not improve $f(S,C)$, yet the k-clustering is not optimal

## Solution

The points are: (0, 0), (0, 6), (0, 2), (6, 2)

Let the centers be (0, 3), (2, 3)

The $f(S,C)$ at begginig is $2 \times (3)^2 +  (2 \times (3)^2) = 36$

Now lets choose the best center for each cluster, the centers will not change because they're already the centroids of the clusters

After that, We will attach the points to the nearest centers, which will not change anything because they're already attached to the nearest centers

Then the answer will remain $36$

meanwhile there is a better answer if we selected the centers (0, 1), (6, 1), the $f(S,C) = 2 \times (1)^2 + 2 \times (3)^2 = 4$
