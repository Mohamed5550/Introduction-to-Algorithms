#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node *parent;
};


void leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;

    if(x->right != NULL) {
        x->right->parent = x;
    }

    if(x->parent == NULL) {
        // make y the tree root
    }

    if(x->parent->left == x) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    x->parent = y;
    y->left = x;
}

int main()
{

}