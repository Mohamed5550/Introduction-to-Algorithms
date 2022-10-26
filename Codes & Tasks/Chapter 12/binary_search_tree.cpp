#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node *parent;
};

struct BST
{
    Node *root = NULL;

    void insert(Node *n)
    {
        Node *x = root;
        Node *y = NULL;
        while(x != NULL)
        {
            y = x;
            if(n->key >= x->key)
                x = x->right;
            else
                x = x->left;
        }
        n->parent = y;
        if(y == NULL)
        {
            this->root = n;
        } else if(n->key < n->parent->key)
        {
            n->parent->left = n;
        } else n->parent->right = n;
    }
    void insert(int n)
    {
        Node *x = new Node;
        x->key = n;
        this->insert(x);
    }

    Node *min(Node *x)
    {
        Node *y = x;
        while(y->left != NULL) {
            y = y->left;
        }

        return y;
    }

    Node *successor(Node *x)
    {
        if(x->right != NULL)
        {
            return this->min(x->right);
        } else 
        {
            Node *y = x->parent;
            while(y != NULL && y->right == x) {
                x = y;
                y = y->parent;
            }

            return y;
        }
    }

    void transplant(Node *u, Node *v)
    {
        if(this->root == u) {
            this->root = v;
        }
        else if(u->parent->left == u) u->parent->left = v;
        else u->parent->right = v;

        if(v != NULL)
            v->parent = u->parent;
    }

    void erase(Node *n)
    {
        if(n == NULL) return;
        if(n->left == NULL) {
            this->transplant(n, n->right);
        } else if(n->right == NULL) {
            this->transplant(n, n->left);
        } else {
            Node *successor = this->successor(n);

            if(successor != n->right) {
                this->transplant(successor, successor->right);
                successor->right = n->right;
            }

            this->transplant(n, successor);
            successor->left = n->left;
        }
    }

    void traverse()
    {
        Node *x = this->min(this->root);
        while(x != NULL) {
            cout << x->key << " ";
            x = this->successor(x);
        }
        cout << "\n";
    }

    Node *find(int x)
    {
        Node *it = root;
        while(it != NULL) {
            if(x == it->key) return it;
            else if(x > it->key) {
                it = it->right;
            } else it = it->left;
        }
        return NULL;
    }

    void erase(int x)
    {
        this->erase(this->find(x));
    }

    Node *max(Node *x) {
        Node *y = x;
        while(y->right != NULL) y = y->right;

        return y;
    }

    Node *predecessor(Node *x)
    {
        if(x->left != NULL)
        {
            return this->max(x->left);
        } else {
            Node *y = x->parent;
            while(y != NULL && y->right != x) {
                x = y;
                y = y->parent;
            }

            return y;
        }
    }
};

int main()
{
    BST *t = new BST;
    t->insert(5);
    t->insert(4);
    t->insert(7);
    t->insert(8);
    t->insert(9);
    t->insert(1);

    t->traverse();

    t->erase(7);
    t->traverse();

    cout << "8 predecessor is: " << t->predecessor(t->find(8))->key;
}