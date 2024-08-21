#include <iostream>
using namespace std;

struct node
{
    int value;
    node *prev;
    node *next;
};

struct douList
{
    node *head;
    node *tail;
};

douList *createList(int x)
{
    douList *l = new douList;
    l->head = new node;
    l->head->value = x;
    l->head->next = NULL;
    l->head->prev = NULL;
    l->tail = l->head;
    return l;
}

douList *addHead(douList *l, int x)
{
    node *tmp = new node;
    tmp->value = x;
    tmp->prev = NULL;
    tmp->next = l->head;
    l->head->prev = tmp;
    l->head = tmp;
    return l;
}

douList *addTail(douList *l, int x)
{
    node *tmp = new node;
    tmp->value = x;
    tmp->prev = l->tail;
    tmp->next = NULL;
    l->tail->next = tmp;
    l->tail = tmp;
    return l;
}

douList *deleteHead(douList *l)
{
    node *p = l->head->next;
    node *temp = l->head;
    p->prev = NULL;
    l->head = p;
    delete (temp);
    return l;
}

douList *deleteTail(douList *l)
{
    node *p = l->tail->prev;
    node *temp = l->tail;
    p->next = NULL;
    l->tail = p;
    delete (temp);
    return l;
}
douList *deleteAt(douList *l, int k)
{
    node *p = l->head;
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    node *temp = p->next;
    node *p2 = temp->next;
    p->next = p2;
    p2->prev = p;
    delete (temp);
    return l;
}

douList *addAt(douList *l, int index, int x)
{
    node *tmp = l->head;
    for (int i = 0; i < index - 1; i++)
    {
        tmp = tmp->next;
    }
    node *newNode = new node;
    newNode->value = x;
    newNode->prev = tmp;
    newNode->next = tmp->next;
    tmp->next->prev = newNode;
    tmp->next = newNode;
    return l;
}

void printList(douList *l)
{
    node *tmp = l->head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
}

int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    douList *l = createList(x);
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        l = addTail(l, x);
    }
    int index, value;
    cin >> index >> value;
    if (index == 0)
    {
        l = addHead(l, value);
    }
    else if (index == n)
    {
        l = addTail(l, value);
    }
    else
    {
        l = addAt(l, index, value);
    }
    printList(l);
    return 0;
}