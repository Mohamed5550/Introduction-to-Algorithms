#include <bits/stdc++.h>
using namespace std;

int partition(vector <int> &v, int l, int r) {

    int x = l;
    for(int i = l; i < r; i++) {
        if(v[i] <= v[r]) {
            swap(v[x], v[i]);
            x ++;
        }
    }

    swap(v[x], v[r]);
    return x;
}

int randomized_partition(vector <int> &v, int l, int r) {
    srand(time(NULL));
    int i = rand()%(r-l+1) + l;

    swap(v[i], v[r]);

    return partition(v, l, r);
}

int quick_select(vector <int> &v, int l, int r, int i) {
    if(l == r) return v[l];

    int q = randomized_partition(v, l, r);

    if(i == q) return v[q];

    if(i < q) return quick_select(v, l, q-1, i);
    else return quick_select(v, q+1, r, i);
}

int main() {
    int n;
    cin >> n;

    vector <int> v(n+1);
    for(int i = 1; i <= n; i ++) cin >> v[i];

    int k;
    cin >> k;

    cout << quick_select(v, 1, n, k);
}