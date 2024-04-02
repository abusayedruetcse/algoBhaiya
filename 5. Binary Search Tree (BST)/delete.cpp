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
    
    // direct first node delete.
    void deleteFirstNode()
    {
        // Case: 1
        if (root->left == NULL)
        {
            root = root->right;
            return;
        }
        
        if (root->right == NULL)
        {
            root = root->left;
            return;
        }
        
        // Case: 2
        Node *p = root->right;
        if (p->left == NULL)
        {
            p->left = root->left;
            root = p;
        }
        else 
        {
            Node *c = p->left;
            while (c->left != NULL)
            {
                p = c;
                c = c->left;
            }
            p->left = c->right;
            
            c->left = root->left;
            c->right = root->right;
            
            root = c;
        }
    }
    
    Node* deleteTargetNode(Node *target)
    {
        // Case: 1
        if (target->left == NULL)
        {
            return target->right;
        }
        
        if (target->right == NULL)
        {
            return target->left;
        }
        
        // Case: 2
        Node *p = target->right;
        if (p->left == NULL)
        {
            p->left = target->left;
            return p;
        }
        else 
        {
            Node *c = p->left;
            while (c->left != NULL)
            {
                p = c;
                c = c->left;
            }
            p->left = c->right;
            
            c->left = target->left;
            c->right = target->right;
            
            return c;
        }
    }
    
    // Use generic delete method
    void deleteRootNode()
    {
        root = deleteTargetNode(root);
    }
};

int main()
{
    BST *bstree = new BST();
    bstree->insert(10);
    bstree->insert(6);
    bstree->insert(15);
    bstree->insert(4);
    bstree->insert(7);
    bstree->insert(12);
    bstree->insert(20);
    bstree->insert(11);
    bstree->print();
    cout<<"Delete\n"<<endl;
    bstree->deleteFirstNode();
    bstree->print();
    cout<<"Delete2\n"<<endl;
    bstree->deleteRootNode();
    bstree->print();
    return 0;
}