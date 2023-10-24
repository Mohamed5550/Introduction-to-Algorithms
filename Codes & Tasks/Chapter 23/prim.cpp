#include <bits/stdc++.h>

using namespace std;

struct vertix
{
    int other;
    int weight;
};

vector <vector<vertix>> g;
vector <vector<vertix>> mst;

void prim()
{
    priority_queue<int> int;
}

int main()
{
    int v, e; cin >> v >> e;
    g.assign(v+1, vector<vertix>());
    mst.assign(v+1, vector<vertix>());

    for(int i = 1; i <= e; i ++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    prim();
}