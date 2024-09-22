#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
};

typedef Node *Tree;

Node *createNode(int value)
{
    Node *p = new Node;
    p->value = value;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void init(Tree &t)
{
    t = nullptr;
}

void addNode(Tree &t, int value)
{
    if (t == nullptr)
    {
        t = createNode(value);
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

void findReplacementAndDelete(Tree &temp, Tree &right)
{
    if (right->left == nullptr)
    {
        findReplacementAndDelete(temp, right->left);
    }
    else
    {
        temp->value = right->value;
        temp = right;
        right = right->right;
    }
}

void deleteNode(Tree &t, int value)
{
    if (t == nullptr)
        return;

    if (value > t->value)
    {
        deleteNode(t->right, value);
    }
    else if (value < t->value)
    {
        deleteNode(t->left, value);
    }
    else
    {
        Node *temp = t;
        if (t->left == nullptr)
        {
            t = t->right;
        }
        else if (t->right == nullptr)
        {
            t = t->left;
        }
        else
        {
            findReplacementAndDelete(temp, t->right);
        }
    }
}

int main()
{
    return 0;
}