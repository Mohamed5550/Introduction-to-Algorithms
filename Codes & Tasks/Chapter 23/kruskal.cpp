#include <bits/stdc++.h>

using namespace std;

struct vertix
{
    int other;
    int weight;
};

vector <vector<vertix>> g;
vector <pair<int, pair<int, int>>> edges;
vector <vector<vertix>> mst;
vector <int> parents;
vector <int> ranks;

void makeSet(int x)
{
    parents[x] = x;
    ranks[x] = 0;
}

void linkSets(int a, int b) {
    if(ranks[a] < ranks[b])
        parents[a] = b;
    else {
        parents[a] = b;
        if(ranks[a] == ranks[b])
            ranks[b] ++;
    }

}

void unionSets(int a, int b)
{
    linkSets(parents[a], parents[b]);
}

int findSet(int x)
{
    if(parents[x] != x) parents[x] = findSet(parents[x]);

    return parents[x];
}

void kruskal()
{
    sort(edges.begin(), edges.end());
    for(auto i: edges) {
        if(findSet(i.second.first) != findSet(i.second.second)) {
            unionSets(i.second.first, i.second.second);
            mst[i.second.first].push_back({i.second.second, i.first});
            mst[i.second.second].push_back({i.second.first, i.first});
        }
    }
}

int main()
{
    int v, e; cin >> v >> e;
    g.assign(v+1, vector<vertix>());
    mst.assign(v+1, vector<vertix>());
    parents.assign(v+1, 0);
    ranks.assign(v+1, 0);
    for(int i = 1; i <= e; i ++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
        edges.push_back({w, {a, b}});
    }

    for(int i = 1; i <= v; i ++) {
        makeSet(i);
    }

    kruskal();

    // testing result
    for(int i = 1; i <= v; i ++) {
        cout << i << ": \n";
        for(auto j: mst[i]) cout << j.other << " " << j.weight << "\n";
        cout << "\n";
    }
}


/*
9 14

1 2 4
1 8 8 
2 3 8
2 8 11
3 4 7
3 9 2
3 6 4
4 5 9
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7

*/