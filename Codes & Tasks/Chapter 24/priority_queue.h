#include <bits/stdc++.h>
using namespace std;

vector <int> pq_index;

int left(int i) {
    return 2*i;
}

int right(int i) {
    return left(i)+1;
}

int parent(int i) {
    return i/2;
}

void heapify(vector <pair<long long, int>> &pq, int i) {
    int greatest = i;
    
    if(left(i) < pq.size() && pq[left(i)] > pq[i]) {
        greatest = left(i);
    }

    if(right(i) < pq.size() && pq[right(i)] > pq[greatest]) {
        greatest = right(i);
    }

    if(greatest != i) {
        swap(pq_index[pq[i].second], pq_index[pq[greatest].second]);
        swap(pq[i], pq[greatest]);
        heapify(pq, greatest);
    }
}

void increaseKey(vector <pair<long long, int>> &pq, int i) {
    while(i > 1 && pq[i] > pq[parent(i)]) {
        swap(pq_index[pq[i].second], pq_index[pq[parent(i)].second]);
        swap(pq[i], pq[parent(i)]);
        i = parent(i);
    }
}

void push(vector <pair<long long, int>> &pq, pair<long long, int> a) {
    pq.push_back(a);
    pq_index[a.second] = pq.size() - 1;
    increaseKey(pq, pq.size() - 1);
}

void pop(vector <pair<long long, int>> &pq) {
    swap(pq_index[pq[1].second], pq_index[pq.back().second]);
    swap(pq[1], pq.back());
    pq.pop_back();
    heapify(pq, 1);
}

pair<long long, int> top(vector<pair<long long, int>> &pq) {
    return pq[1];
}