#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data)
        {
            this->data=data;
            left=NULL;
            right=NULL;
        }
};

class BST
{
    Node *root = NULL;

    void insert(Node *root, int value)
    {
        Node *newNode = new Node(value);

        if (this->root == NULL) {
            this->root = newNode;
            return;
        }

        if (value <= root->data) {
            if (root->left == NULL) {
                root->left = newNode;
            } else {
                insert(root->left, value);
            }
        } else {
            if (root->right == NULL) {
                root->right = newNode;
            } else {
                insert(root->right, value);
            }
        }
    }

    void print(Node *root)
    {
        if (root == NULL) {
            return;
        }

        printf("Data: %d, left: %d, right: %d\n", root->data, root->left, root->right);

        print(root->left);
        print(root->right);
    }

public:
    void insert(int value)
    {
        insert(root, value);
    }

    void print()
    {
        print(root);
    }
};

int main()
{
    BST *bstree = new BST();
    bstree->insert(5);
    bstree->insert(7);
    bstree->insert(3);
    bstree->insert(6);
    bstree->print();
    return 0;
}