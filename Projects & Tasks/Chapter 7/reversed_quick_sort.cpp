#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int first, int last) {
    bool same = 1;
    for(int i = first+1; i <= last; i ++) {
        same &= v[i] == v[i-1];
    }

    int x = v[last];
    int i = first-1;
    for(int j = first; j < last; j ++) {
        if(v[j] >= x && (!same || j%2 == last%2)) {
            i ++;
            swap(v[j], v[i]);
        }
    }
    i ++;
    swap(v[last], v[i]);
    return i;
}

void quicksort(vector<int> &v, int first, int last) {
    if(last <= first) return;
    int q = partition(v, first, last);
    quicksort(v, first, q-1);
    quicksort(v, q+1, last);
}

void ssort(vector <int> &v) {
    quicksort(v, 0, v.size()-1);
}

int main() {
    int n;
    cin >> n;

    vector <int> v(n);
    for(int i = 0; i < n; i ++) cin >> v[i];
    ssort(v);

    for(auto i: v) cout << i << " ";
    cout << "\n";
}