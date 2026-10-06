# 33.1-1

Show that the objective function $f(S, C)$ can be written in the given format

We will begin with this format
$$
f(S,C) = \sum_{l = 1}^{k} \sum_{x \ in S^{(l)}} \Delta(x, c^{(l)})
$$

We have $c_a^{(l)}$ from this equation (proven from the minimum center of a cluster)

$$
c^{(l)} = \frac{1} {|S^{(l)}|} \sum_{x \in S^{(l)}} x
$$

We expand the delta

$$
f(S,C) = \sum_{l = 1}^{k} (\sum_{x \ in S^{(l)}} x^2 - 2xc^{(l)} + (c^{(l)})^2)
$$

Subistitute in the $c^{(l)}$ equation

$$
f(S,C) = \sum_{l = 1}^{k} \sum_{x \ in S^{(l)}} x^2 - |S^{(l)}|(c^{(l)})^2
$$

So

$$
\sum_{x \ in S^{(l)}} x^2 - |S^{(l)}|(c^{(l)})^2 = \sum_{x \ in S^{(l)}} x^2 - \frac{1}{|S^{(l)}|}\sum_{x \in S} \sum_{y \in S} x.y
$$

We can lead the final formula to this form with the same steps
