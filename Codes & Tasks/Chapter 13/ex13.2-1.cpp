#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node *parent;
};

void rightRotate(Node *x)
{
    Node *y = x->left;
    x->left = y->right;

    if(x->left != NULL) {
        x->left->parent = x;
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
    y->right = x;
}

int main()
{

}