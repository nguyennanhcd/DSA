#include <iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};

node *createNode(int x)
{
    node *head = new node;
    head->value = x;
    head->next = nullptr;
    return head;
}

node *addElement(node *p, int x)
{
    node *newElement = createNode(x);
    p->next = newElement;
    newElement->next = nullptr;
    return newElement;
}

void printList(node *l)
{
    node *p = l;
    while (p != nullptr)
    {
        cout << p->value << " ";
        p = p->next;
    }
}

node *deleteElement(node *l, int index, int &n)
{
    if (index < 0 || index >= n)
    {
        cerr << "Index out of bounds" << endl;
        return l;
    }

    node *p = l;

    if (index == 0)
    {
        l = l->next;
        delete p;
        n--;
        return l;
    }

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }

    node *temp = p->next;
    p->next = p->next->next;
    delete temp;
    n--;

    return l;
}

int main()
{
    int n;
    int x;
    cin >> n;
    cin >> x;
    node *l = createNode(x);
    node *p = l;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        p = addElement(p, x);
    }
    int index;
    cin >> index;
    l = deleteElement(l, index, n);
    printList(l);
    return 0;
}