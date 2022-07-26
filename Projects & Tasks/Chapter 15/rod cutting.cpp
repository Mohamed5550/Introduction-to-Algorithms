#include <bits/stdc++.h>
using namespace std;

vector <int> p;
int n, l;

long long rod(int i, int length, long long v) {
    if(i == l-1) {
        return p[length+1];
    }

    return max(rod(i+1, 0, v+p[length+1]), rod(i+1, length+1, v));
}


int main () {
    cin >> n >> l;
    p.assign(n, 0);
    for(int i = 0; i < n; i ++) {
        cin >> p[i];
    }

    cout << rod(0, 0, 0) << endl;
}