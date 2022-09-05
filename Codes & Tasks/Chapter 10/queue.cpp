#include <iostream>
using namespace std;

const int MX = 1e5;
struct queue {
    int head = 0;
    int tail = 0;
    int arr[MX];
    int n = 0;

    void push(int a) {
        if(n == MX) {
            cout << "queue is full";
            return;
        }
        n ++;
        arr[tail] = a;
        tail = (tail+1)%MX;
    }

    void pop() {
        if(n == 0) {
            cout << "queue is empty";
            return;
        }
        n --;
        head = (head+1)%MX;
    }

    int front() {
        return arr[head];
    }
};

int main() {
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << " ";
    q.pop();
    q.pop();
    q.push(5);
    cout << q.front() << " ";
}