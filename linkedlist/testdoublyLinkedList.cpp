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
    l->head->prev = NULL;
    l->head->next = NULL;
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

douList *removeTail(douList *l)
{
    node *p = l->tail;
    node *tmp = l->tail->prev;
    tmp->next = nullptr;
    l->tail = tmp;
    delete p;
    return l;
}

douList *removeHead(douList *l)
{
    node *p = l->tail->next;
    node *tmp = l->head;
    p->prev = nullptr;
    l->head = p;
    delete tmp;
    return l;
}

int main()
{
    int n, x;
    cin >> n;
    cin >> x;

    return 0;
}