#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *prev;
};

struct Stack {
    int n = 0;
    Node *top;

    void push(int a) {
        n ++;
        Node *temp = new Node {
            a,
            this->top
        };
        this->top = temp;
    }

    void pop() {
        n --;
        Node *temp = this->top;
        this->top = this->top->prev;

        delete temp;
    }

    int topElement() {
        return this->top->key;
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(4);
    s.push(3);
    cout << s.topElement() << " ";
    s.pop();
    cout << s.topElement() << " ";
    s.push(8);
    cout << s.topElement() << " ";
}