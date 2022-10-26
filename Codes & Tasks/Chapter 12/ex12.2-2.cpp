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

int tree_maximum(Node *n) {
    if(n->right == NULL) return n->value;
    
    return tree_maximum(n->right); 
}

int tree_minimum(Node *n) {
    if(n->left == NULL) return n->value;

    return tree_minumum(n->left);
}

int main()
{

}