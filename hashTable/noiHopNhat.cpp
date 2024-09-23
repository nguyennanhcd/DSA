#include <iostream>
#define M 7
using namespace std;

struct Item
{
    int value;
    int next;
};

struct HashTable
{
    Item h[M];
    int r;
};

void initHashTable(HashTable &t)
{
    for (int i = 0; i < M; i++)
    {
        t.h[i].value = -1;
        t.h[i].next = -1;
    }

    t.r = M - 1;
}

int hashFunction(int x)
{
    return x % M;
}

void insertHashItem(HashTable &t, int x)
{
    // check if there is an empty space in the hash table
    if (t.r >= 0)
    {
        int idx = hashFunction(x);
        if (t.h[idx].value == -1)
        {
            t.h[idx].value = x;
        }
        else
        {
            t.h[t.r].value = x;
            // neu next cua vi tri hien tai dang la - 1 thi se cho idx = vi tri cua noi xay ra dung do
            while (t.h[idx].next != -1)
            {
                idx = t.h[idx].next;
            }
            // assign next to the position of r
            t.h[idx].next = t.r;
        }
        // find a new proper space for r
        while (t.r >= 0 && t.h[t.r].value >= 0)
        {
            t.r--;
        }
    }
}

void display(HashTable t)
{
    for (int i = 0; i < M; i++)
    {
        cout << "Bucket " << i << ":" << "\t" << t.h[i].value << " : " << t.h[i].next << endl;
    }
}

void search(HashTable t, int x)
{
    int h = hashFunction(x);
    if (t.h[h].value == x)
    {
        cout << x << " found in the table";
        return;
    }
    if (t.h[h].value == -1)
    {
        cout << x << " not found in the table";
        return;
    }
    while (t.h[h].next != -1)
    {
        h = t.h[h].next;
        if (t.h[h].value == x)
        {
            cout << x << " found in the table";
            return;
        }
    }

    cout << x << " not found in the table\n";
}

int search2(HashTable t, int x)
{
    int idx = hashFunction(x);
    do
    {
        if (t.h[idx].value == x)
        {
            return idx;
        }

        idx = t.h[idx].next;
    } while (idx >= 0);

    return -1;
}

void removeItem(HashTable &t, int x)
{
    int idx = hashFunction(x);
    int prev = -1; // To track the previous index

    // If the item is in the head bucket
    if (t.h[idx].value == x)
    {
        if (t.h[idx].next == -1) // No chaining, simply remove
        {
            t.h[idx].value = -1;
        }
        else // There is chaining, promote the next node
        {
            int nextIdx = t.h[idx].next;
            t.h[idx].value = t.h[nextIdx].value;
            t.h[idx].next = t.h[nextIdx].next;
            t.h[nextIdx].value = -1; // Remove the node from the table
            t.h[nextIdx].next = -1;
        }
        cout << x << " removed from the table.\n";
        return;
    }

    // Traverse the chain to find the item
    while (t.h[idx].next != -1)
    {
        prev = idx;
        idx = t.h[idx].next;

        if (t.h[idx].value == x)
        {
            t.h[prev].next = t.h[idx].next; // Unlink the current item
            t.h[idx].value = -1;
            t.h[idx].next = -1;
            cout << x << " removed from the table.\n";
            return;
        }
    }

    cout << x << " not found in the table.\n";
}

int main()
{
    HashTable t;
    initHashTable(t);
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
            insertHashItem(t, value);
            break;
        case 2:
            display(t);
            break;
        case 3:
        {
            cout << "Enter value to search: ";
            cin >> value;
            search(t, value);
        }
        case 4:
        {
            cout << "Enter value to remove: ";
            cin >> value;
            removeItem(t, value);
            break;
        }

        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 3);
    return 0;
}