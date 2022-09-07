#include <iostream>
using namespace std;

const int MX = 1e5;

struct deque {
    int n = 0;
    int arr[MX];
    int tail = 0;
    int head = 0;

    void push_back(int a) {
        n ++;
        arr[tail] = a;
        tail = (tail+1)%MX;
    }

    void push_front(int a) {
        n ++;
        head = (head-1+MX)%MX;
        arr[head] = a;
    }

    void pop_back() {
        n --;
        tail = (tail-1+MX)%MX;
    }

    void pop_front() {
        n --;
        head = (head+1)%MX;
    }

    void traverse() {
        for(int i = 0; i < n; i ++) {
            cout << arr[(head+i)%MX] << " ";
        }
    }
};

int main () {

    deque d;
    d.push_back(2);
    d.push_front(3);
    d.push_front(5);
    d.pop_back();
    d.pop_front();
    d.push_back(6);
    d.push_front(7);
    d.traverse();
}