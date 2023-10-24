#include <bits/stdc++.h>

using namespace std;

struct vertix {
    int parent = 0;
    int key = INT_MAX;
    int value;
    int pqindex;
};

struct edge {
    int other;
    int weight;
};

int left(int i) {
    return 2*i;
}

int right(int i) {
    return left(i)+1;
}

int parent(int i) {
    return i/2;
}

void heapify(vector <vertix*> &pq, int i) {
    int smallest = i;
    
    if(left(i) < pq.size() && pq[left(i)]->key < pq[i]->key) {
        smallest = left(i);
    }

    if(right(i) < pq.size() && pq[right(i)]->key < pq[smallest]->key) {
        smallest = right(i);
    }

    if(smallest != i) {
        swap(pq[i]->pqindex, pq[smallest]->pqindex);
        swap(pq[i], pq[smallest]);
        heapify(pq, smallest);
    }
}

void decreaseKey(vector <vertix*> &pq, int i) {
    while(i > 1 && pq[i]->key < pq[parent(i)]->key) {
        swap(pq[i]->pqindex, pq[parent(i)]->pqindex);
        swap(pq[i], pq[parent(i)]);
        i = parent(i);
    }
}

void push(vector <vertix*> &pq, vertix *a) {
    a->pqindex = pq.size();
    pq.push_back(a);
    decreaseKey(pq, pq.size() - 1);
}

void pop(vector <vertix*> &pq) {
    swap(pq[1]->pqindex, pq.back()->pqindex);
    swap(pq[1], pq.back());
    pq.pop_back();
    heapify(pq, 1);
}

vertix *top(vector<vertix*> &pq) {
    return pq[1];
}

vector <vector<edge>> g;
vector <vector<edge>> mst;
vector <bool> inQ;
vector <vertix*> pqPointers;

void prim()
{
    vector <vertix*>  pq(1); // empty space to start with index 1
    for(int i = 1; i < g.size(); i ++) {
        vertix *x = new vertix;
        x->value = i;
        pqPointers[i] = x;
        push(pq, x);
    }

    while(pq.size() > 1) {
        vertix *u = top(pq);
        inQ[u->value] = 0;
        if(u->parent) {
            mst[u->value].push_back({u->parent, u->key});
            mst[u->parent].push_back({u->value, u->key});
        }
        pop(pq);
        for(auto i: g[u->value]) {
            if(inQ[i.other] && i.weight < pqPointers[i.other]->key) {
                pqPointers[i.other]->key = i.weight;
                pqPointers[i.other]->parent = u->value;
                decreaseKey(pq, pqPointers[i.other]->pqindex);
            }
        }
    }
}

int main()
{
    int v, e; cin >> v >> e;
    g.assign(v+1, vector<edge>());
    mst.assign(v+1, vector<edge>());
    inQ.assign(v+1, 1);
    pqPointers.assign(v+1, new vertix);

    for(int i = 1; i <= e; i ++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    prim();

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