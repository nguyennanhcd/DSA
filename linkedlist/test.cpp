#include <iostream>
using namespace std;
struct node
{
    int value;
    node *next;
};

node *createNode(int value)
{
    node *newNode = new node;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

node *insertNode(node *p, int value)
{
    node *newNode = new node;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

node *deleteNode(node *l, int value)
{
    if (l == NULL)
    {
        return NULL;
    }

    if (l->value == value)
    {
        node *temp = l;
        l = l->next;
        delete temp;
        return l;
    }

    node *tmp = l;

    while (tmp->next != NULL && tmp->next->value != value)
    {
        tmp = tmp->next;
    }
    tmp->next = tmp->next->next;
    tmp->next = NULL;
    return l;
}

int main()
{
    return 0;
}