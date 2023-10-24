#include <bits/stdc++.h>
using namespace std;

// left, right and top of the current node
int left(int i) {
    return i*2;
}

int right(int i) {
    return i*2+1;
}

// you can see the descrtion in heap.cpp file
// there is additional part here which is the size of the heap(last)
void max_heapify(vector <int> &heap, int i, int last) {
    int greatest = i;
    int l = left(i);
    int r = right(i);

    if(l <= last && heap[i] < heap[l]) {
        greatest = l;
    }

    if(r <= last && heap[greatest] < heap[r]) {
        greatest = r;
    }

    if(greatest != i) {
        swap(heap[i], heap[greatest]);
        max_heapify(heap, greatest, last);
    }
}

// building a heap from an array
vector <int> build(vector <int> &v) {
    int n = 1;
    while(n < v.size()) {
        n *= 2;
    }
    n *= 2;
    vector <int> heap(n, 0);
    for(int i = 1; i <= v.size(); i ++) {
        heap[i] = v[i-1];
    }

    for(int i = n/2; i > 0; i --) {
        max_heapify(heap, i, v.size());
    }

    return heap;
}

// we just swap the first and last element to put the last in its sorted position
// Then we resize the heap to exclude the last element from it
void heap_sort(vector <int> &v) {
    vector <int> heap = build(v);

    for(int i = v.size(); i > 1; i --) {
        swap(heap[i], heap[1]);
        max_heapify(heap, 1, i-1);
    }

    for(int i = 0; i < v.size(); i ++) {
        v[i] = heap[i+1];
    }
}

int main() {
    int n;
    cin >> n;

    vector <int> v(n);
    for(int i = 0; i < n; i ++) cin >> v[i];

    heap_sort(v);
    for(auto i: v) cout << i << " ";
}