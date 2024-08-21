#include <iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};

node *createNode(int x)
{
    node *tmp = new node;
    tmp->value = x;
    tmp->next = nullptr;
    return tmp;
}

node *addElement(node *p, int x)
{
    node *temp = createNode(x);
    p->next = temp;
    return temp;
}

void printList(node *l)
{
    node *p = l;
    while (p != NULL)
    {
        cout << p->value << " ";
        p = p->next;
    }
}

int main()
{
    int n, x;
    cin >> n;
    cin >> x;
    node *l = createNode(x);
    node *p = l;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        p = addElement(p, x);
    }
    printList(l);
    return 0;
}
