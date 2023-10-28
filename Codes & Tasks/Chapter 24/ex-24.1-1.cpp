#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct edge {
    int v; // other edge
    int w; // weight
};

struct vertix {
    int p; // parent
    long long d; // distance
};

int v, e;
vector <vector<edge>> g;
vector <vertix> distances;


void readGraph()
{
    cin >> v >> e;
    g.assign(v+1, vector<edge>());
    for(int i = 1; i <= e; i ++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
    }
}

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
                relax(j, k.v, k.w);
            }
        }
    }
}

int main()
{

    readGraph();

    bellmanFord(1);
    cout << distances[1].d << " " << distances[2].d << " " << distances[3].d << " " << distances[4].d << " " << distances[5].d << "\n"; 

    cout << distances[2].d << " " << distances[2].p << "\n";
}

/*
s: 1
t: 2
x: 3
y: 4
z: 5

5 10
2 3 5
2 4 8
2 5 -4
3 2 -2
4 3 -3
4 5 9
5 3 4
5 1 2
1 2 6
1 4 7
*/
