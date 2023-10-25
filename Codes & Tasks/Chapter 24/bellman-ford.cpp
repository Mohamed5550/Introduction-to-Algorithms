#include <bits/stdc++.h>

using namespace std;

struct edge {
    int other;
    int weight;
};

struct vertix {
    int p; // parent
    int d; // distamce
};

int v, e;
vector <vector<edge>> g;
vector <vertix> distances;


void relax(int u, int v, int w)
{
    if(distances[v].d > distances[u].d + w) {
        distances[v].d = distances[u].d + w;
        distances[v].p = u;
    }
}

void bellmanFord(int s)
{
    distances.assign(v+1, {0, INT_MAX});
    distances[s].d = 0;

    for(int i = 1; i <= v; i ++) {
        for(int j = 1; j <= v; j ++) {
            for(auto k: g[j]) {
                relax(j, k.other, k.weight);
            }
        } 
    }
}

void printPath(int s, int d)
{
    if(s != d)
        printPath(s, distances[d].p);
    cout << d << " > ";
}

int main()
{
    cin >> v >> e;
    g.assign(v+1, vector<edge>());

    for(int i = 1; i <= e; i ++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
    }

    int s = 1; // source
    int d = 3; // destination 
    bellmanFord(s);
    printPath(s, 5);
}

/*
s: 1
t: 2
x: 3
y: 4
z: 5

5 10
1 2 3
2 3 6
3 5 2
5 3 7
4 5 6
4 5 4
4 2 1
2 4 2
1 4 5
5 1 3
*/