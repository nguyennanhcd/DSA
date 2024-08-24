#include <iostream>
using namespace std;
struct node
{
    int value;
    node *prev;
    node *next;
};

struct doublyLikedList
{
    node *head;
    node *tail;
};

doublyLikedList *createList(int x)
{
    doublyLikedList *l = new doublyLikedList;
    l->head = new node;
    l->head->value = x;
    l->head->prev = NULL;
    l->head->next = NULL;
    l->tail = l->head;
    return l;
}

doublyLikedList *addTail(doublyLikedList *l, int x)
{
    node *newNode = new node;
    newNode->value = x;
    newNode->prev = l->tail->prev;
    newNode->next = NULL;
    l->tail = newNode;
    return l;
}

doublyLikedList *addHead(doublyLikedList *l, int x)
{
    node *newNode = new node;
    newNode->value = x;
    newNode->prev = NULL;
    newNode->next = l->head;
    l->head = newNode;
    return l;
}

doublyLikedList *deleteFirst(doublyLikedList *l)
{
    node *tmp = new node;
    tmp = nullptr;
    l->head = tmp;
    l->head->prev = tmp;
    delete tmp;
    return l;
}

doublyLikedList *addAt(doublyLikedList *l, int x, int index)
{
    node *newNode = new node;
    node *tmp = l->head;
    for (int i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }
    return l;
}
int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    doublyLikedList *list = createList(x);
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        list = addTail(list, x);
    }
    return 0;
}