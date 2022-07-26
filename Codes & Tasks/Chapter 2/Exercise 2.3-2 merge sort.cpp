#include <bits/stdc++.h>
using namespace std;

vector <int> m_merge(vector <int> v1, vector <int> v2) {
    vector <int> v;
    
    int i1 = 0, i2 = 0;
    while(i1 < v1.size() || i2 < v2.size()) {
        if(i1 == v1.size()) {
            v.push_back(v2[i2]);
            i2 ++;
            continue;
        }

        if(i2 == v2.size()) {
            v.push_back(v1[i1]);
            i1 ++;
            continue;
        }
        
        if(v1[i1] <= v2[i2]) {
            v.push_back(v1[i1]);
            i1 ++;
        } else {
            v.push_back(v2[i2]);
            i2 ++;
        }
    }

    return v;
}

vector <int> merge_sort(int l, int r, vector <int>& v) {
    if(r - l == 1) {
        vector <int> vo = {v[l]};
        return vo;
    }
    
    int m = (l+r)/2;
    return m_merge(merge_sort(l, m, v), merge_sort(m, r, v));
}

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector <int> v(n);
    for(int i = 0; i < n; i ++) {
        cin >> v[i];
    }

    vector <int> sorted = merge_sort(0, n, v);

    for(auto i: sorted) {
        cout << i << " ";
    }

}