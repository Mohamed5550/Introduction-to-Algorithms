#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *left = NULL;
    Node *right = NULL;
    Node *parent = NULL;
};

struct Tree {
    Node *root = NULL;
};

Node *tree_maximum(Node *n) {
    if(n->right == NULL) return n;
    
    return tree_maximum(n->right); 
}

Node *predecessor(Node *n)
{
    if(n->left != NULL) return tree_maximum(n->left);

    Node *y = n->parent;
    while(y != NULL && n == y->left) {
        n = y;
        y = y->parent;
    }

    return y;
}

int main()
{

}