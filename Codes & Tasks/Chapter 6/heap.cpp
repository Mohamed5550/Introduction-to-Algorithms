#include <bits/stdc++.h>
using namespace std;

// left, right and top of the current node
int left(int i) {
    return 2*i;
}

int right(int i) {
    return 2*i+1;
}

int parent(int i) {
    return i/2;
}


// putting the current node in its correct place
// get the largest of left, right and current node and put it in the top
// then recurse of the current node if its position has changed
void heapify(vector <int> &heap, int i) {
    
    int greater = i;
    
    if(left(i) < heap.size() && heap[i] < heap[left(i)]) {
        greater = left(i);
    }

    if(right(i) < heap.size() && heap[greater] < heap[right(i)]) {
        greater = right(i);
    }

    if(greater != i) {
        swap(heap[i], heap[greater]);
        heapify(heap, greater);
    }

}


// building a heap from an array
void build(vector<int> &v, vector <int> &heap) {
    int n = 1;
    while(n < v.size()) {
        n *= 2;
    }

    heap.assign(n, 0);

    for(int i = 1; i < v.size(); i ++) {
        heap[i] = v[i];
    }

    cout << heap.size() << endl;

    for(int i = n/2; i > 0; i --) {
        heapify(heap, i);
    }
}

int main() {
    int n;
    cin >> n;

    vector <int> v(n+1);
    for(int i = 1; i <= n; i ++) cin >> v[i];

    vector <int> heap;
    build(v, heap);

    for(int i = 1; i < heap.size(); i ++) {
        cout << heap[i] << " ";
    }
    
}