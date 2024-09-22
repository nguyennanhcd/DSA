#include <iostream>
using namespace std;
#define M 11

struct Node
{
    int value;
    Node *next;
};

Node *newNode(int x)
{
    Node *newNode = new Node;
    newNode->value = x;
    newNode->next = NULL;
    return newNode;
}

int hashFunction(int value)
{
    return value % M;
}

void initHashTable(Node *heads[])
{
    for (int i = 0; i < M; i++)
    {
        heads[i] = NULL;
    }
}

void insert(Node *heads[], int value)
{
    int h = hashFunction(value);
    Node *r = heads[h];
    Node *prev = NULL;
    while (r != NULL && r->value < value)
    {
        prev = r;
        r = r->next;
    }

    Node *p = newNode(value);
    if (!prev)
    {
        heads[h] = p;
        p->next = r;
    }
    else if (!r)
    {
        prev->next = p;
    }
    else
    {
        prev->next = p;
        p->next = r;
    }
}

void display(Node *heads[])
{
    for (int i = 0; i < M; i++)
    {
        cout << "Bucket " << i << ": ";
        Node *r = heads[i];
        while (r)
        {
            cout << r->value << " ";
            r = r->next;
        }
        cout << endl;
    }
}

int main()
{
    return 0;
}