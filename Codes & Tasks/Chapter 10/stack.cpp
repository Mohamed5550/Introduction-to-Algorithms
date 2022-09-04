#include <iostream>
using namespace std;
const int MX = 1e6;

struct stack {
    int n = 0;
    int arr[MX];

    void push(int a) {
        arr[n++] = a;
    }

    void pop() {
        if(n == 0) {
            cout << "Stack is empty";
            return;
        }

        n --;
    }


    int top() {
        return arr[n-1];
    }

    int size() {
        return n;
    }
};

int main() {
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top() << " ";
    s.pop();
    cout << s.top() << " ";
    s.push(4);
    cout << s.top() << " ";
    cout << s.size() << " ";
}