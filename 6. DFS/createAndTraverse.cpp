// Online C++ compiler to run C++ program online
#include <iostream>

class Node
{
    public:
    int data;
    Node * links[10];
    int countOfLink = 0;
};

Node *visited[100];
int totalVisited = 0; // global variable

bool isVisited(Node *src)
{
    bool hasFound = false; // flag
    for (int i = 0; i < totalVisited; i++)
    {
        if (visited[i] == src)
        {
            printf("Checked");
            hasFound = true;
            break;
        }
    }
    return hasFound;
}

void traverse(Node *src)
{
    if (src == NULL || isVisited(src))
    {
        return;
    }
    
    printf("Data: %d\n",src->data);
    
    for (int i = 0; i < src->countOfLink; i++)
    {
        visited[totalVisited] = src;
        totalVisited++;
        traverse(src->links[i]);
    }
}

    
int main() {
    
    Node *src = new Node();
    src->data = 5;
    
    Node *n8 = new Node();
    n8->data = 8;
    // linking
    src->links[src->countOfLink] = n8;
    src->countOfLink++;
    
    Node *n6 = new Node();
    n6->data = 6;
    // linking
    src->links[src->countOfLink] = n6;
    src->countOfLink++;
    // linking
    n8->links[n8->countOfLink] = n6;
    n8->countOfLink++;

    Node *n10 = new Node();
    n10->data = 10;
    // linking
    src->links[src->countOfLink] = n10;
    src->countOfLink++;  
    
    Node *n12 = new Node();
    n12->data = 12;
    // linking
    n10->links[n10->countOfLink] = n12;
    n10->countOfLink++; 
    
    Node *n13 = new Node();
    n13->data = 13;
    // linking
    n12->links[n12->countOfLink] = n13;
    n12->countOfLink++; 
    // linking
    n13->links[n13->countOfLink] = n10;
    n13->countOfLink++; 
    
    traverse(src);
    return 0;
}