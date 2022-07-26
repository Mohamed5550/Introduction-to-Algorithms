#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; // count, max
    cin >> n >> k;

    vector <int> v(n+1);

    vector <int> pre(k+1);

    for(int i = 1; i <= n; i ++) {
        cin >> v[i];
        pre[v[i]] ++;
    }

    for(int i = 1; i <= k; i ++) {
        pre[i] += pre[i-1];
    }
    

    int q;
    cin >> q;
    while(q --) {
        int a, b;
        cin >> a >> b;

        cout << pre[b] - pre[a-1] << "\n";
    }
}