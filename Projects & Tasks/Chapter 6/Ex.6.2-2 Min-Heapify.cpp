#include <bits/stdc++.h>

using namespace std;

int left(int i) {
    return i/2;
}

int right(int i) {
    return i/2+1;
}

void min_heapify(vector <int> &v, int i) {
    int l = left(i);
    int r = right(i);

    int smallest = i;
    if(l < v.size() && v[l] < v[i]) {
        smallest = l;
    }
    if(r < v.size() && v[r] < v[smallest]) {
        smallest = r;
    }

    swap(v[i], v[smallest]);
    if(v[i] != smallest) {
        min_heapify(v, smallest);
    }
}

int main() {
    
}