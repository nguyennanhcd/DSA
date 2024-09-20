#include <iostream>
using namespace std;
#define M 101

struct Node
{
    int value;
    Node *next;
};

int hashFunction(int value)
{
    return value % M;
}

void initHash(Node *heads[])
{
    for (int i = 0; i < M; i++)
    {
        heads[i] = NULL;
    }
}
void display(Node *heads[])
{
    for (int i = 0; i < M; i++)
    {
        if (heads[i])
        {
            cout << "Bucket " << i << ": ";
            Node *p = heads[i];
            while (p != NULL)
            {
                cout << p->value << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
}

Node *search(Node *heads[], int value)
{
    int h = hashFunction(value);
    Node *r = heads[h];
    while (r != NULL && r->value != value)
    {
        r = r->next;
    }
    return r;
}

Node *newNode(int x)
{
    Node *newNode = new Node;
    newNode->value = x;
    newNode->next = NULL;
    return newNode;
}

void insert(Node *heads[], int value)
{
    int h = hashFunction(value);
    Node *r = heads[h];
    Node *prev = NULL;

    while (r != NULL && r->value < value)
    {
        prev = r;
        r = r->next;
    }

    Node *p = newNode(value);
    if (!prev) // them vao dau
    {
        heads[h] = p;
        p->next = r;
    }
    else if (!r) // them vao cuoi
    {
        prev->next = p;
    }
    else
    { // them vao truoc cua r
        p->next = r;
        prev->next = p;
    }
}

void remove(Node *heads[], int value)
{
    int h = hashFunction(value);
    Node *r = heads[h];
    Node *prev = NULL;

    while (r != NULL)
    {
        if (r->value == value)
        {
            if (r == heads[h]) // removing the first node
            {
                heads[h] = r->next;
            }
            else // removing a node in the middle or at the end
            {
                prev->next = r->next;
            }
            delete r;
            return; // exit the function after deleting the node
        }
        prev = r;
        r = r->next;
    }
}

int main()
{
    Node *heads[M];
    initHash(heads);
    int choice, value;

    do
    {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Search\n";
        cout << "4. Remove\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insert(heads, value);
            break;
        case 2:
            display(heads);
            break;
        case 3:
        {
            cout << "Enter value to search: ";
            cin >> value;
            Node *a = search(heads, value);
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
        {
            cout << "Enter value to remove: ";
            cin >> value;
            remove(heads, value);
            break;
        }
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 5);
    return 0;
}