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
    g.assign(n+1, vector<int>(n+1));
    parents.assign(n+1, 0);
    ranks.assign(n+1, 0);

    for(int i = 1; i <= n; i ++) makeSet(i);

    for(int i = 1; i <= e; i ++) {
        int a, b; cin >> a >> b;
        if(findSet(a) != findSet(b) || findSet(a) * findSet(b) == 0) {
            unionSets(a, b);
        }
    }

    set <int> s;
    for(int i = 1; i <= n; i ++) {
        cout << i << " " << findSet(i) << "\n";
        s.insert(findSet(i));
    }

    cout << "Number of connected components is: " << s.size() << "\n";

    
}

/**
10 7
1 2 
1 3 
2 3 
2 4 
5 6 
5 7
8 9 
 * 
 */