#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> v;

pair<int, int> secondSmallest(int l, int r) {
    if(l == r) return {v[l], 1e9};
    if(r == l+1) return {min(v[l], v[r]), max(v[l], v[r])};

    int m = (l+r)/2;
    pair <int, int> p1 = secondSmallest(l, m);
    pair <int, int> p2 = secondSmallest(m+1, r);

    return {min(p1.first, p2.first), min(max(p1.first, p2.first), min(p1.second, p2.second))};
}

int main() {
    cin >> n;
    v.assign(n, 0);
    for(int i = 0; i < n; i ++) cin >> v[i];

    // finding the second smallest element
    cout << secondSmallest(0, n-1).second;
}