#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> g;
vector <int> heads;
vector <int> nexts;

void makeSet(int a)
{
    heads[a] = a;
    nexts[a] = a;
}

int findSet(int a)
{
    return heads[a];
}

void unionSets(int a, int b)
{
    // always puttig a into b
    int heada = heads[a], headb = heads[b];
    int x = nexts[a];
    while(x != a) {
        heads[x] = heads[b];
        x = nexts[x];
    }
    heads[a] = heads[b];

    swap(nexts[heada], nexts[headb]);

}

int main()
{
    int n, e; cin >> n >> e;
    g.assign(n+1, vector<int>());
    heads.assign(n+1, 0);
    nexts.assign(n+1, 0);

    for(int i = 1; i <= n; i ++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}