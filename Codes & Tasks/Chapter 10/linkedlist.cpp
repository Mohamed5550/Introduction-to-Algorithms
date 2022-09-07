#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *next;
    Node *prev;
};

struct LinkedList {
    int n = 0;

    Node *head = new Node {
        0,
        NULL,
        NULL
    };

    void insert(int x) {
        n ++;
        Node *temp = new Node {
            x,
            this->head->next,
            this->head
        };

        if(this->head->next)
            this->head->next->prev = temp;
        this->head->next = temp;
    }

    void erase(Node *thisNode) {
        n --;
        if(thisNode->next)
            thisNode->next->prev = thisNode->prev;
        
        if(thisNode->prev)
            thisNode->prev->next = thisNode->next;

        delete thisNode;
    }

    Node *find(int x) {
        Node *it = this->head->next;
        while(it != NULL) {
            if(it->key == x) return it;
            it = it->next;
        }

        return NULL;
    }

    int size() {
        return n;
    }

    void traverse() {
        Node *it = this->head->next;
        while(it != NULL) {
            cout << it->key << " ";
            it = it->next;
        }
    }
};

int main() {
    LinkedList list;
    list.insert(5);
    list.insert(2);
    list.insert(4);
    list.insert(7);
    list.insert(1);

    list.erase(list.find(5));
    list.insert(9);
    list.erase(list.find(1));
    list.traverse();

}