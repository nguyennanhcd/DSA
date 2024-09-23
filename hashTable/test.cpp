#include <iostream>
using namespace std;
#define M 11

struct Node
{
    int value;
    Node *next;
};

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

Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertHashTable(Node *heads[], int value)
{
    int h = hashFunction(value);
    Node *r = heads[h];
    Node *prev = NULL;
    while (r != nullptr && r->value < value)
    {
        prev = r;
        r = r->next;
    }

    Node *p = createNode(value);
    if (prev == nullptr)
    {
        heads[h] = p;
        p->next = r;
    }
    else if (r == nullptr)
    {
        prev->next = p;
    }
    else
    {
        prev->next = p;
        p->next = r;
    }
}

void deleteHashTable(Node *heads[], int value)
{
    int h = hashFunction(value);
    Node *r = heads[h];
    Node *prev = nullptr;
    while (r != nullptr)
    {
        if (r->value == value)
        {
            if (r == heads[h])
            {
                heads[h] = r->next;
            }
            else
            {
                prev->next = r->next;
            }
            delete r;
            return;
        }
        prev = r;
        r = r->next;
    }
}

int main()
{
    return 0;
}