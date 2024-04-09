
#include <iostream>
#include <string.h>

class Node
{
    public:
    Node *link[26];
    bool isEndAWord;
};

void verifyWord(Node *root, char word[])
{
    Node *temp = root;
    for (int i = 0; i< strlen(word); i ++)
    {
        temp = temp->link[word[i]-'a'];
    }
    
    if (temp->isEndAWord)
    {
        printf("It is a word\n");
    }
    else
    {
        printf("It is not a word\n");
    }
}


void insert(Node *root, char word[])
{
    Node *temp = root;
    for (int i = 0; i < strlen(word); i++)
    {
        if (temp->link[word[i]-'a'] == NULL)
        {
            Node *newNode = new Node();
            temp->link[word[i]-'a'] = newNode;
        }
        temp = temp->link[word[i]-'a'];
    }
    temp->isEndAWord = true;
}

int main() {
    
    // an, // and
    Node *root = new Node();
    
    char word1[] = {'a', 'n'};
    char word2[] = {'a', 'n', 'd'};
    char word3[] = {'a', 'n', 't'};
    char word4[] = {'a', 'd', 'd'};
    char word5[] = {'a', 'd'};
    
    insert(root, word1);
    insert(root, word2);
    insert(root, word3);
    insert(root, word4);
    
    verifyWord(root, word3);
    verifyWord(root, word4);
    
    return 0;
}