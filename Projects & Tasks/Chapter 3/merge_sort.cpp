#include <bits/stdc++.h>

using namespace std;


vector <int> merge_a(vector<int> a, vector<int> b) {
    vector <int> merged;

    int i = 0, j = 0;
    while(i < a.size() || j < b.size()) {
        int x;
        if(i >= a.size()) {
            x = b[j];
            j ++;
            merged.push_back(x);
            continue;
        }

        if(j >= b.size()) {
            x = a[i];
            i ++;
            merged.push_back(x);
            continue;
        }

        if(a[i] <= b[j]) {
            x = a[i];
            i ++;
        } else {
            x = b[j];
            j ++;
        }
        merged.push_back(x);
    }

    return merged;
}

vector <int> merge_sort(vector <int> v) {
    if(v.size() == 1) {
        return v;
    }

    int l = 0;
    int r = v.size();
    int m = l+(r-l)/2;

    vector <int> vl;
    for(int i = 0; i < m; i ++) {
        vl.push_back(v[i]);
    }

    vector <int> vr;
    for(int i = m; i < r; i ++) {
        vr.push_back(v[i]);
    }


    return merge_a(merge_sort(vl), merge_sort(vr));
}

int main() {

    int n;
    cin >> n;
    vector <int> v(n);

    for(int i = 0; i < n; i ++) cin >> v[i];


    vector <int> sorted = merge_sort(v);

    for(auto i: sorted) cout << i << " ";

}