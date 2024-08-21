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

int findValueAtIndex(node *l, int index)
{
    node *p = l;
    int currentIndex = 0;
    while (p != nullptr)
    {
        if (currentIndex == index)
        {
            return p->value;
        }
        p = p->next;
        currentIndex++;
    }
    return -1;
}

int main()
{
    int n;
    int x;
    cin >> n;
    if (n <= 0)
    {
        cout << "The list must have at least one element." << endl;
        return 1;
    }

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

    int value = findValueAtIndex(l, index);
    cout << value;

    return 0;
}
