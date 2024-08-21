#include <iostream>
using namespace std;
struct node
{
    int value;
    node *next;
};
node *first;

void init()
{
    first = NULL;
}

void traverse()
{
    node *temp = first;
    if (temp != NULL)
    {
        do
        {
            cout << temp->value << " ";
            temp = temp->next;

        } while (temp != NULL);
    }
}

void addHead(int x)
{
    node *tmp = new node;
    tmp->value = x;
    tmp->next = first;
    node *p = first;
    if (p != nullptr)
    {
        while (p != first)
        {
            p = p->next;
        }
        p->next = tmp;
    }
    else
    {
        tmp->next = tmp;
    }
    first = tmp;
}

int main()
{
    return 0;
}