#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> g;
vector <int> parents;
vector <int> ranks;

void makeSet(int a)
{
    parents[a] = a;
    ranks[a] = 0;
}

int findSet(int a)
{
    if(a != parents[a]) {
        parents[a] = findSet(parents[a]);
    }

    return parents[a];
}

void linkSets(int a, int b) {
    if(ranks[a] > ranks[b]) {
        parents[b] = a;
    } else {
        parents[a] = b;

        if(ranks[a] == ranks[b]) ranks[b] ++;
    }
}

void unionSets(int a, int b)
{
    linkSets(findSet(a), findSet(b));
}

int main()
{
    int n, e; cin >> n >> e;
    g.assign(n+1, vector<int>());
    parents.assign(n+1, 0);
    ranks.assign(n+1, 0);

    for(int i = 1; i <= n; i ++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}