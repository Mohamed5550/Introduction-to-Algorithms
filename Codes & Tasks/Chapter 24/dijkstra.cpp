#include <iostream>
#include <vector>
#include <limits.h>
#include "priority_queue.h"

using namespace std;

void fast() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}

struct edge {
    int other;
    int weight;
};

struct vertix {
    int p; // parent
    long long d; // distance
};

int v, e;
vector <vector<edge>> g;
vector <vertix> distances;


void relax(int u, int v, long long w)
{
    if(distances[v].d - w > distances[u].d) {
        distances[v].d = distances[u].d + w;
        distances[v].p = u;
    }
}

void dijkstra(int s)
{
    distances.assign(v+1, {0, LLONG_MAX});
    distances[s].d = 0;
    vector <pair<long long, int>>  pq(1); // -distance, vertex
    pq_index.assign(v+1, -1);

    for(int i = 1; i <= v; i ++) {
        push(pq, {-distances[i].d, i});
    }

    for(int i = 1; i <= v; i ++) {
        pair<long long, int> x = top(pq);
        pop(pq);

        for(auto j: g[x.second]) {
            long long oldDist = distances[j.other].d;
            relax(x.second, j.other, j.weight);
            if(distances[j.other].d < oldDist) {
                pq[pq_index[j.other]] = {-distances[j.other].d, j.other};
                increaseKey(pq, pq_index[j.other]);
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
    fast();
 
    freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    cin >> v >> e;
    g.assign(v+1, vector<edge>());

    for(int i = 1; i <= e; i ++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
    }

    int s = 5; // source
    int d = 3; // destination 
    dijkstra(s);
    // cout << "distances: ";
    // for(int i = 1; i <= v; i ++) cout << distances[i].d << " ";
    // cout << "\n";
    cout << "Shortest path from " << s << " to " << d << " has weight: " << distances[d].d << "\n";
    printPath(s, d);
    return 0;
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