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
    node *tmp = createNode(x);
    p->next = tmp;
    return tmp;
}

void changeList(node *l, int updateNum, int changeNum)
{
    node *p = l;
    while (p != nullptr)
    {
        if (p->value == updateNum)
        {
            p->value = changeNum;
        }
        p = p->next;
    }
}

void printList(node *l)
{
    node *p = l;
    while (p != nullptr)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteList(node *l)
{
    node *p;
    while (l != nullptr)
    {
        p = l;
        l = l->next;
        delete p;
    }
}

int main()
{
    int x, n;
    cin >> n;
    cin >> x;
    node *l = createNode(x);
    node *p = l;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        p = addElement(p, x);
    }
    int updateNum, changeNum;
    cin >> updateNum >> changeNum;
    changeList(l, updateNum, changeNum);
    printList(l);

    deleteList(l);

    return 0;
}
