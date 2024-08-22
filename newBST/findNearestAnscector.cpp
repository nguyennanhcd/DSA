#include <iostream>
using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
};

typedef node *Tree;

void init(Tree &t)
{
    t = NULL;
}

void addNode(Tree &t, int value)
{
    if (t == nullptr)
    {
        node *p = new node();
        p->value = value;
        p->left = nullptr;
        p->right = nullptr;
        t = p;
    }
    else
    {
        if (value < t->value)
        {
            addNode(t->left, value);
        }
        else if (value > t->value)
        {
            addNode(t->right, value);
        }
    }
}

void printNode(Tree t)
{
    if (t != nullptr)
    {
        printNode(t->left);
        cout << t->value << " ";
        printNode(t->right);
    }
}

void deleteNode(Tree &t, int value)
{
    if (t == nullptr)
        return;
    if (value < t->value)
    {
        deleteNode(t->left, value);
    }
    else if (value > t->value)
    {
        deleteNode(t->right, value);
    }
    else
    {
        if (t->left = nullptr)
        {
            t = t->right;
        }
        else if (t->right = nullptr)
        {
            t = t->left;
        }
        else
        {
        }
    }
}
int main()
{
    Tree t;
    init(t);
    return 0;
}