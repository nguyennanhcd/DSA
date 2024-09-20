#include <iostream>
using namespace std;
#define M 101

struct Node
{
    int key;
    Node *next;
};

Node *heads[M];
Node *z;

void init()
{
    z = new Node;
    z->next = z;
    for (int i = 0; i < M; i++)
    {
        heads[i] = z;
    }
}

void insert(int k)
{
    Node *t = heads[k % M];
    Node *x = new Node;
    x->key = k;
    // z->key = k;
    if (t->key >= k)
    {
        x->next = t;
        heads[k % M] = x;
    }
    else
    {
        Node *p = t->next;
        while (p != z && p->key < k)
        {
            t = t->next;
            p = t->next;
        }
        t->next = x;
        x->next = p;
    }
}

Node *search(int k)
{
    Node *t = heads[k % M];
    z->key = k;
    while (t != z && t->key < k)
    {
        t = t->next;
    }
    if (t->key != k)
    {
        return nullptr;
    }
    return t;
}

void display()
{
    for (int i = 0; i < M; i++)
    {
        Node *t = heads[i];
        cout << "Bucket " << i << ": ";
        while (t != z)
        {
            cout << t->key << " ";
            t = t->next;
        }
        cout << endl;
    }
}

void deleteNum(int k)
{
}

int main()
{
    init();
    int choice, value;

    do
    {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insert(value);
            break;
        case 2:
            display();
            break;
        case 3:
        {
            cout << "Enter value to search: ";
            cin >> value;
            Node *a = search(value);
            if (a)
            {
                cout << value << " found in the hash table.\n";
            }
            else
            {
                cout << value << " not found in the hash table.\n";
            }
            break;
        }
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
