#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> g;
vector <pair<int, pair<int, int>>> edges;
vector <vector<int>> mst;

void kruskal()
{
    sort(edges.begin(), edges.end());
    for(auto i: edges) {
        if(findSet(i.second.first) != findSet(i.second.second)) {
            unionSets(i.second.first, i.second.second);
            mst[i.second.first].push_back(i.second.second);
            mst[i.second.second].push_back(i.second.first);
        }
    }
}

int main()
{
    int v, e; cin >> v >> e;
    g.assign(v+1, vector<int>());
    mst.assign(v+1, vector<int>())
    for(int i = 1; i <= e; i ++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back(b);
        g[b].push_back(a);
        edges.push_back({w, {a, b}});
    }

    kruskal();
}