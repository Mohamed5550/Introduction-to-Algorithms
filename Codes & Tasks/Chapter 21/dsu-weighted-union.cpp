#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> g;
vector <int> heads;
vector <int> nexts;
vector <int> sizes;

void makeSet(int a)
{
    heads[a] = a;
    nexts[a] = a;
    sizes[a] = 1;
}

int findSet(int a)
{
    return heads[a];
}

void unionSets(int a, int b)
{
    // move the smaller one into the larger
    if(sizes[heads[a]] > sizes[heads[b]]) swap(a, b);

    // always puttig a into b
    int heada = heads[a], headb = heads[b];
    int x = nexts[a];
    while(x != a) {
        heads[x] = heads[b];
        x = nexts[x];
    }
    heads[a] = heads[b];
    sizes[heads[b]] += sizes[heads[a]]; 

    swap(nexts[heada], nexts[headb]);

}

int main()
{
    int n, e; cin >> n >> e;
    g.assign(n+1, vector<int>());
    heads.assign(n+1, 0);
    nexts.assign(n+1, 0);
    sizes.assign(n+1, 0);

    for(int i = 1; i <= n; i ++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}