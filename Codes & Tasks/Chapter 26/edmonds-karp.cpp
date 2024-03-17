#include <bits/stdc++.h>

using namespace std;

#define oo 1000000000

vector <vector<int>> C; // capacities
vector <vector<int>> F; // flows
vector <vector<int>> R; // residual network
vector <vector<int>> RG; // residual network as ajcaency list
vector <int> parents; // in shortest paths
vector <int> distances;
int v, e; // vertices, edges
int s, t; // source, sink

bool bfs()
{
    queue<int> q; // vertix
    distances.assign(v+1, oo);
    parents.assign(v+1, 0);
    distances[s] = 0;
    q.push(s);
    while(q.size()) {
        int x = q.front(); q.pop();
        for(auto i: RG[x]) {
            if(!R[x][i]) continue;
            if(distances[i] == oo) {
                q.push(i);
                distances[i] = distances[x] + 1;
                parents[i] = x;
            }
        }
    }

    return distances[t] != oo;
}

int EdmondsKarp()
{
    while(bfs()) {
        // augment by shortest path and make residual network
        int c = oo; // residual capacity
        auto it = t;
        while(it != s) {
            c = min(c, R[parents[it]][it]);
            it = parents[it];
        }
        
        it = t;
        while(it != s) {
            if(C[parents[it]][it]) {
                F[parents[it]][it] += c;
                R[parents[it]][it] = C[parents[it]][it] - F[parents[it]][it];
                R[it][parents[it]] = F[parents[it]][it];
            } else {
                F[it][parents[it]] -= c;
                R[parents[it]][it] = F[it][parents[it]];
                R[it][parents[it]] = C[it][parents[it]] - F[it][parents[it]];
            }
            it = parents[it];
        }
    }

    int maxFlow = 0;
    for(int i = 1; i <= v; i ++) {
        maxFlow = maxFlow + F[s][i] - F[i][s];
    }

    return maxFlow;
}

int main()
{
    cin >> v >> e;
    cin >> s >> t;
    C.assign(v+1, vector<int>(v+1));
    R.assign(v+1, vector<int>(v+1));
    F.assign(v+1, vector<int>(v+1));
    RG.assign(v+1, vector<int>());

    // getting edges and capacities from user
    for(int i = 1; i <= e; i ++) {
        int a, b, c; cin >> a >> b >> c;
        C[a][b] += c;
        R[a][b] += c;
        RG[a].push_back(b);
        RG[b].push_back(a);
    }

    cout << "Max flow is: " << EdmondsKarp() << "\n";
}

// first example
/*
4 5
1 4 
1 2 1000000
1 3 1000000
2 3 1
3 4 1000000
2 4 1000000
*/

// second example
/*
6 9
1 6
1 2 16
1 3 13
2 4 12
3 2 4
3 5 14
4 3 9
4 6 20
5 4 7
5 6 4
*/