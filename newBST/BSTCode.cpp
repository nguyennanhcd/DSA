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

Node *init(Tree &t)
{
    t = NULL;
}

void addNode(Tree &t, int value)
{
    if (t == nullptr)
    {
        t = createNode(value);
    }
    else
    {
        if (value > t->value)
        {
            addNode(t->right, value);
        }
        else if (value < t->value)
        {
            addNode(t->left, value);
        }
    }
}

Tree search(Tree &t, int value)
{
    if (t != nullptr)
    {
        if (value == t->value)
        {
            return t;
        }
        else
        {
            if (value > t->value)
            {
                return search(t->right, value);
            }
            else
            {
                return search(t->left, value);
            }
        }
    }
}

void printLNR(Tree &t)
{
    if (t != nullptr)
    {
        printLNR(t->left);
        cout << t->value << " ";
        printLNR(t->right);
    }
}

void printLeavesNode(Tree &t)
{
    if (t != nullptr)
    {
        if (t->left == nullptr && t->right == nullptr)
        {
            cout << t->value << " ";
        }
        printLeavesNode(t->left);
        printLeavesNode(t->right);
    }
}

void printNodesHaveTwoChildren(Tree &t)
{
    if (t != nullptr)
    {
        if (t->left != nullptr && t->right != nullptr)
        {
            cout << t->value << " ";
        }
        printNodesHaveTwoChildren(t->left);
        printNodesHaveTwoChildren(t->right);
    }
}

Tree maxNode(Tree &t)
{
    if (t->right == nullptr)
    {
        return t;
    }
    return maxNode(t->right);
}

Tree minNode(Tree &t)
{
    if (t->left == nullptr)
    {
        return t;
    }
    return minNode(t->left);
}

void findReplacementNode(Node *&temp, Node *&left)
{
    if (left->right != nullptr)
    {
        findReplacementNode(temp, left->right);
    }
    else
    {
        temp->value = left->value;
        temp = left;
        left = left->left;
    }
}

void deleteNode(Tree &t, int value)
{
    if (!t)
    {
        cout << "Tree is empty";
        return;
    }
    else
    {
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
                findReplacementNode(temp, t->left);
            }
        }
    }
}

int main()
{
    return 0;
}