#include <iostream>
using namespace std;

struct BTreeNode
{
    int *keys;
    int t;
    BTreeNode **C;
    int n;
    bool leaf;
};

struct BTree
{
    BTreeNode *root;
    int t;
};

BTreeNode *createNode(int t, bool leaf);

void initBTree(BTree *tree, int t);

int findKey(BTreeNode *node, int k);

void removeFromLeaf(BTreeNode *node, int idx);

int getPredecessor(BTreeNode *node, int idx);

int getSuccessor(BTreeNode *node, int idx);

void borrowFromPrev(BTreeNode *node, int idx);

void borrowFromNext(BTreeNode *node, int idx);

void merge(BTreeNode *node, int idx);

void fill(BTreeNode *node, int idx);

void deletion(BTreeNode *node, int k);

void removeFromNonLeaf(BTreeNode *node, int idx);

void insertNonFull(BTreeNode *node, int k);

void splitChild(BTreeNode *node, int i, BTreeNode *y);

void insertion(BTree *tree, int k);

void traverse(BTreeNode *node);

void deleteFromTree(BTree *tree, int k);

int main()
{
    BTree t;
    initBTree(&t, 3);

    int choice, value;

    do
    {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Remove\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertion(&t, value);
            break;
        case 2:
            cout << "The B-tree is: ";
            if (t.root != NULL)
                traverse(t.root);
            cout << endl;
            break;
        case 3:
            cout << "Enter value to remove: ";
            cin >> value;
            deleteFromTree(&t, value);
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}

BTreeNode *createNode(int t, bool leaf)
{
    BTreeNode *newNode = new BTreeNode;
    newNode->t = t;
    newNode->leaf = leaf;
    newNode->keys = new int[2 * t - 1];
    newNode->C = new BTreeNode *[2 * t];
    newNode->n = 0;
    return newNode;
}

void initBTree(BTree *tree, int t)
{
    tree->root = NULL;
    tree->t = t;
}

int findKey(BTreeNode *node, int k)
{
    int idx = 0;
    while (idx < node->n && node->keys[idx] < k)
        ++idx;
    return idx;
}

void removeFromLeaf(BTreeNode *node, int idx)
{
    for (int i = idx + 1; i < node->n; ++i)
        node->keys[i - 1] = node->keys[i];
    node->n--;
}

int getPredecessor(BTreeNode *node, int idx)
{
    BTreeNode *cur = node->C[idx];
    while (!cur->leaf)
        cur = cur->C[cur->n];
    return cur->keys[cur->n - 1];
}

int getSuccessor(BTreeNode *node, int idx)
{
    BTreeNode *cur = node->C[idx + 1];
    while (!cur->leaf)
        cur = cur->C[0];
    return cur->keys[0];
}

void borrowFromPrev(BTreeNode *node, int idx)
{
    BTreeNode *child = node->C[idx];
    BTreeNode *sibling = node->C[idx - 1];

    for (int i = child->n - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];

    if (!child->leaf)
    {
        for (int i = child->n; i >= 0; --i)
            child->C[i + 1] = child->C[i];
    }

    child->keys[0] = node->keys[idx - 1];

    if (!child->leaf)
        child->C[0] = sibling->C[sibling->n];

    node->keys[idx - 1] = sibling->keys[sibling->n - 1];

    child->n += 1;
    sibling->n -= 1;
}

void borrowFromNext(BTreeNode *node, int idx)
{
    BTreeNode *child = node->C[idx];
    BTreeNode *sibling = node->C[idx + 1];

    child->keys[child->n] = node->keys[idx];

    if (!child->leaf)
        child->C[child->n + 1] = sibling->C[0];

    node->keys[idx] = sibling->keys[0];

    for (int i = 1; i < sibling->n; ++i)
        sibling->keys[i - 1] = sibling->keys[i];

    if (!sibling->leaf)
    {
        for (int i = 1; i <= sibling->n; ++i)
            sibling->C[i - 1] = sibling->C[i];
    }

    child->n += 1;
    sibling->n -= 1;
}

void merge(BTreeNode *node, int idx)
{
    BTreeNode *child = node->C[idx];
    BTreeNode *sibling = node->C[idx + 1];

    child->keys[node->t - 1] = node->keys[idx];

    for (int i = 0; i < sibling->n; ++i)
        child->keys[i + node->t] = sibling->keys[i];

    if (!child->leaf)
    {
        for (int i = 0; i <= sibling->n; ++i)
            child->C[i + node->t] = sibling->C[i];
    }

    for (int i = idx + 1; i < node->n; ++i)
        node->keys[i - 1] = node->keys[i];

    for (int i = idx + 2; i <= node->n; ++i)
        node->C[i - 1] = node->C[i];

    child->n += sibling->n + 1;
    node->n--;

    delete sibling;
}

void fill(BTreeNode *node, int idx)
{
    if (idx != 0 && node->C[idx - 1]->n >= node->t)
        borrowFromPrev(node, idx);
    else if (idx != node->n && node->C[idx + 1]->n >= node->t)
        borrowFromNext(node, idx);
    else
    {
        if (idx != node->n)
            merge(node, idx);
        else
            merge(node, idx - 1);
    }
}

void deletion(BTreeNode *node, int k)
{
    int idx = findKey(node, k);

    if (idx < node->n && node->keys[idx] == k)
    {
        if (node->leaf)
            removeFromLeaf(node, idx);
        else
            removeFromNonLeaf(node, idx);
    }
    else
    {
        if (node->leaf)
        {
            cout << "The key " << k << " does not exist in the tree\n";
            return;
        }

        bool flag = ((idx == node->n) ? true : false);

        if (node->C[idx]->n < node->t)
            fill(node, idx);

        if (flag && idx > node->n)
            deletion(node->C[idx - 1], k);
        else
            deletion(node->C[idx], k);
    }
}

void removeFromNonLeaf(BTreeNode *node, int idx)
{
    int k = node->keys[idx];

    if (node->C[idx]->n >= node->t)
    {
        int pred = getPredecessor(node, idx);
        node->keys[idx] = pred;
        deletion(node->C[idx], pred);
    }
    else if (node->C[idx + 1]->n >= node->t)
    {
        int succ = getSuccessor(node, idx);
        node->keys[idx] = succ;
        deletion(node->C[idx + 1], succ);
    }
    else
    {
        merge(node, idx);
        deletion(node->C[idx], k);
    }
}

void insertNonFull(BTreeNode *node, int k)
{
    int i = node->n - 1;

    if (node->leaf)
    {
        while (i >= 0 && node->keys[i] > k)
        {
            node->keys[i + 1] = node->keys[i];
            i--;
        }

        node->keys[i + 1] = k;
        node->n = node->n + 1;
    }
    else
    {
        while (i >= 0 && node->keys[i] > k)
            i--;

        if (node->C[i + 1]->n == 2 * node->t - 1)
        {
            splitChild(node, i + 1, node->C[i + 1]);

            if (node->keys[i + 1] < k)
                i++;
        }
        insertNonFull(node->C[i + 1], k);
    }
}

void splitChild(BTreeNode *node, int i, BTreeNode *y)
{
    BTreeNode *z = createNode(y->t, y->leaf);
    z->n = node->t - 1;

    for (int j = 0; j < node->t - 1; j++)
        z->keys[j] = y->keys[j + node->t];

    if (!y->leaf)
    {
        for (int j = 0; j < node->t; j++)
            z->C[j] = y->C[j + node->t];
    }

    y->n = node->t - 1;

    for (int j = node->n; j >= i + 1; j--)
        node->C[j + 1] = node->C[j];

    node->C[i + 1] = z;

    for (int j = node->n - 1; j >= i; j--)
        node->keys[j + 1] = node->keys[j];

    node->keys[i] = y->keys[node->t - 1];
    node->n = node->n + 1;
}

void insertion(BTree *tree, int k)
{
    if (tree->root == NULL)
    {
        tree->root = createNode(tree->t, true);
        tree->root->keys[0] = k;
        tree->root->n = 1;
    }
    else
    {
        if (tree->root->n == 2 * tree->t - 1)
        {
            BTreeNode *s = createNode(tree->t, false);
            s->C[0] = tree->root;
            splitChild(s, 0, tree->root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            insertNonFull(s->C[i], k);

            tree->root = s;
        }
        else
            insertNonFull(tree->root, k);
    }
}

void traverse(BTreeNode *node)
{
    int i;
    for (i = 0; i < node->n; i++)
    {
        if (!node->leaf)
            traverse(node->C[i]);
        cout << " " << node->keys[i];
    }

    if (!node->leaf)
        traverse(node->C[i]);
}

void deleteFromTree(BTree *tree, int k)
{
    if (!tree->root)
    {
        cout << "The tree is empty\n";
        return;
    }

    deletion(tree->root, k);

    if (tree->root->n == 0)
    {
        BTreeNode *tmp = tree->root;
        if (tree->root->leaf)
            tree->root = NULL;
        else
            tree->root = tree->root->C[0];

        delete tmp;
    }
}
