#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

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


void relax(int u, int v, int w)
{
    if(distances[v].d > distances[u].d + w) {
        distances[v].d = distances[u].d + w;
        distances[v].p = u;
    }
}

void dijkstra(int s)
{
    distances.assign(v+1, {0, INT_MAX});
    distances[s].d = 0;
    priority_queue<pair<int, int>> pq; // -distance, vertix

    for(int i = 1; i <= v; i ++) {
        pq.push({-distances[i].d, i});
    }

    for(int i = 1; i <= v; i ++) {
        pair<int, int> x = pq.top();
        pq.pop();

        for(auto j: g[x.second]) {
            relax(x.second, j.other, j.weight);
            pq.push({-distances[i].d, j.other});
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
    dijkstra(s);
    cout << "distances: ";
    for(int i = 1; i <= v; i ++) cout << distances[i].d << " ";
    cout << "\n";
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