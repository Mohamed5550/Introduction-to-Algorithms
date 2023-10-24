#include <bits/stdc++.h>
using namespace std;

int left(int i) {
    return 2*i;
}

int right(int i) {
    return left(i)+1;
}

int parent(int i) {
    return i/2;
}

void heapify(vector <int> &pq, int i) {
    int greatest = i;
    
    if(left(i) < pq.size() && pq[left(i)] > pq[i]) {
        greatest = left(i);
    }

    if(right(i) < pq.size() && pq[right(i)] > pq[greatest]) {
        greatest = right(i);
    }

    if(greatest != i) {
        swap(pq[i], pq[greatest]);
        heapify(pq, greatest);
    }
}

void increaseKey(vector <int> &pq, int i, int a) {
    while(i > 1 && pq[i] > pq[parent(i)]) {
        swap(pq[i], pq[parent(i)]);
        i = parent(i);
    }
}

void push(vector <int> &pq, int a) {
    pq.push_back(a);
    increaseKey(pq, pq.size() - 1, a);
}

void pop(vector <int> &pq) {
    swap(pq[1], pq.back());
    pq.pop_back();
    heapify(pq, 1);
}

int top(vector<int> &pq) {
    return pq[1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int>  pq(1); // zero index
    
    while(n --) {
        string s;
        cin >> s;

        if(s == "push") {
            int a;
            cin >> a;
            push(pq, a);
        } else {
            if(pq.size() == 1) {
                cout << "IT IS JUST EMPTY\n";
                continue;
            }
            if(s == "pop") {
                pop(pq);
            } else {
                cout << top(pq) << "\n";
            }
        }
    }
}