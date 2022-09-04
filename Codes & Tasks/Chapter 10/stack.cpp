#include <iostream>
using namespace std;
const int MX = 1e6;

struct stack {
    int size = 0;
    int arr[MX];

    void push(int a) {
        arr[size++] = a;
    }

    void pop() {
        if(size == 0) {
            cout << "Stack is empty";
            return;
        }

        size --;
    }


    int top() {
        return arr[size-1];
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
}