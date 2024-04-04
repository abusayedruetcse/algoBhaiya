#include<iostream>
using namespace std;

int visited[100]={};
int visitedCount=0;

class Node
{
    public:
        int data;
        Node *links[10];
        int countLink;

        Node (int data)
        {
            this->data=data;
            links[10]={};
            countLink=0;
        }
};

class DFS
{
    Node *root = NULL;
    public:
    //function to check is the value is printed or not
    bool hasVisited(int val)
    {
        bool isVisited=false;
        for(int i=0;i<visitedCount;i++)
        {
            if(val==visited[i])
            {
                isVisited=true;
                break;
            }
        }
        return isVisited;
    }

    void traverse(Node *root)
    {
        if(root==NULL)
            return;
        
        if (hasVisited(root->data))
        {
            return;
        }
        
        visited[visitedCount]=root->data;
        visitedCount++;
        cout<<root->data<<"\n";
    
        for(int i=0;i<root->countLink;i++)
        {
            traverse(root->links[i]);
        }
    }
    
    void dfsUsingStack(Node *root)
    {
        stack s;
        s.push(root);
        
        while(!s.empty())
        {
            Node *currentNode = s.pop();
            if (!checkVal(currentNode->data))
            {
                printed[index]=root->data;
                index++;
                cout<<root->data<<"\n";
            }
            
            for(int i=0;i<currentNode->countLink;i++)
            {
                s.push(currentNode->links[i]);
            }
        }
    }
    
    Node *findVertex(int vertex)
    {
        
    }
    
    void edge(int s, int d)
    {
        Node *sNode = findVertex(s);
        if (sNode == NULL)
        {
            sNode = new Node(s);
        }
        
        Node *dNode = findVertex(d);
        if (dNode == NULL)
        {
            dNode = new Node(d);
        }
        
        // linking
        sNode->links[sNode->countLink] = dNode;
        sNode->countLink++;
        dNode->links[dNode->countLink] = sNode;
        dNode->countLink++;
    }
};



int main()
{
    DFS dfs;
    dfs.edge(1,2);
    
    return 0;
}
