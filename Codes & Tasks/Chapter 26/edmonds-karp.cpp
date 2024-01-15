#include <bits/stdc++.h>

using namespace std;

#define oo 1000000000

vector <vector<int>> E; // edges
vector <vector<int>> C; // capacities
vector <vector<int>> F; // flows
vector <vector<int>> R; // residual network capacities
vector <vector<int>> G; // adjacensy list
vector <vector<int>> RG; // residual network as adjacency list
vector <bool> vs;
int v, e; // number of vertices and edges
int s, t; // source, sink
vector <int> pathPrev;

int bfs()
{
    vs.assign(v+1, 0);
    queue<pair<int, int>> q; // vertix, prev vertix
    q.push({s, 0});
    vector <int> distances(v+1, oo);
    pathPrev.assign(v+1, -1);
    distances[s] = 0;
    while(!q.empty()) {
        pair<int, int> v = q.front(); q.pop();
        vs[v.first] = 1;
        if(distances[v.second] + 1 < distances[v.first]) {
            distances[v.first] = distances[v.second] + 1;
            pathPrev[v.first] = v.second;
        }
        for(auto i: RG[v.first]) {
            if(!vs[i]) q.push({i, v.first});
        }
    }

    return distances[t];
}

bool checkResidualNetowrk()
{
    RG.assign(v+1, vector<int>());
    for(int i = 1; i <= v; i ++) {
        for(auto j: G[i]) {
            int c1 = C[i][j] - F[i][j];
            int c2 = F[i][j];
            
            if(c1 > 0) {
                RG[i].push_back(j);
                R[i][j] = c1;
            } else {
                R[i][j] = 0;
            }

            if(c2 > 0) {
                RG[j].push_back(i);
                R[j][i] = c2;
            } else {
                R[j][i] = 0;
            }
        }
    }

    int sp = bfs(); // shortest path

    return sp != oo;
}

int getResidualCapacity()
{
    int c = oo;
    int i = t;
    while(i != s) {
        c = min(c, R[pathPrev[i]][i]);
        i = pathPrev[i];
    }
    return c;
}

int EdmondsKarp()
{
    while(checkResidualNetowrk()) { // there is an augmentation path in the residual network
        int c = getResidualCapacity(); // min capacity in the path
        int i = t;
        while(i != s) {
            c = min(c, R[pathPrev[i]][i]);
            int a = pathPrev[i];
            int b = i;
            if(E[a][b]) F[a][b] += c;
            else F[a][b] -= c;
            
            i = pathPrev[i];
        }
    }

    int maxFlow = 0;
    for(int i = 1; i <= v; i ++) {
        maxFlow += F[s][i];
        maxFlow -= F[i][s];
    }

    return maxFlow;
}

int main()
{
    cin >> v >> e;
    cin >> s >> t;
    E.assign(v+1, vector<int>(v+1));
    C.assign(v+1, vector<int>(v+1));
    F.assign(v+1, vector<int>(v+1));
    R.assign(v+1, vector<int>(v+1));
    G.assign(v+1, vector<int>());

    // getting edges and capacities from user
    for(int i = 1; i <= e; i ++) {
        int a, b, c; cin >> a >> b >> c;
        E[a][b] = 1;
        C[a][b] = c;
        G[a].push_back(b);
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