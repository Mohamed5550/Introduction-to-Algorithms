#include <iostream>
#include <vector>

using namespace std;
int t = 2;

struct BTREE
{
    node root;
    // int t;
};

struct node {
    int n;
    vector <int> keys;
    vector <node> children;
    bool leaf = 0;
};

void disk_read(node x)
{

}

void disk_write(node x)
{

}

pair<node, int> search(node x, int k)
{
    int i = 1;
    while(i <= x.n && k <= x.keys[i])
        i ++;
    
    if(k == x.keys[i])
        return {x, i};
    
    node nullNode;
    if(x.leaf) return {nullNode, 0};

    disk_read(x.children[i]);

    return search(x.children[i], k);
}

void create(BTREE T)
{
    node x;
    x.leaf = 1;
    x.n = 0;
    disk_write(x);
    T.root = x;
}


void insert(BTREE T, int k)
{

}

void split(node x, int i)
{
    node z;
    node y = x.children[i];
    z.leaf = y.leaf;
    z.n = t-1;
    for(int j = 1; j <= z.n; j ++) {
        z.keys[j] = y.keys[t+j];
    }

    if(!z.leaf) {
        for(int j = 1; j <= z.n+1; j ++) {
            z.children[j] = y.children[x.t+j];
        }
    }

    y.n = t-1;

    for(int j = x.n+1; j > i; j --) {
        x.children[j+1] = x.children[j];
    }
    x.children[i+1] = z;

    for(int j = x.n; j >= i; j --) {
        x.keys[j+1] = x.keys[j];
    }
    x.keys[i] = y.keys[t];
    x.n ++;

    disk_write(y);
    disk_write(z);
    disk_write(x);
}

int main()
{

}