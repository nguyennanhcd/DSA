#include <iostream>
using namespace std;
#define M 101
struct Node
{
    int key;
    Node *next;
};
Node *heads[M];
Node *z;

void init()
{
    z = new Node;
    z->next = z;
    for (int i = 0; i < M; i++)
    {
        heads[i] = z;
    }
}

Node *insert(int k)
{
    Node *t = heads[k % M];
    Node *x = new Node;
    x->key = k;
    z->key = k;
    if (t->key >= k)
    {
        x->next = t;
        heads[k % M] = x;
    }
    else
    {
        Node *p = t->next;
        while (p->key < k)
        {
            t = t->next;
            p = t->next;
        }
        t
            ->next = x;
        x->next = p;
    }
    return x;
}

Node *search(int k)
{
    Node *t = heads[k % M];
    z->key = k;
    while (t->key < k)
    {
        t = t->next;
    }
    if (t->key != k)
    {
        return z;
    }
    return t;
}

int main()
{
    return 0;
}