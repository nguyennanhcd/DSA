#include <iostream>
using namespace std;
#define MAX 100
struct node
{
    int value;
    node *next;
};

void init(node **top, int &n)
{
    *top = NULL;
    n = 0;
}

int push(node **top, int &n, int value)
{
    if (n < MAX - 1)
    {
        node *tmp = new node;
        tmp->value = value;
        tmp->next = *top;
        *top = tmp;
        n++;
        return 1;
    }
    return 0;
}

int pop(node **top, int &n, int &value)
{
    if (n >= 0 && top != nullptr)
    {
        value = (*top)->value;
        node *tmp = *top;
        *top = (*top)->next;
        delete tmp;
        n--;
        return 1;
    }
    return 0;
}

int main()
{
    node *top;
    int n;
    init(&top, n);
    return 0;
}