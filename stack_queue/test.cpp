#include <iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};

node *createNode(int x)
{
    node *newNode = new node;
    newNode->value = x;
    newNode->next = nullptr;
    return newNode;
}

void enqueue(node **front, node **rear, int x)
{
    node *newNode = createNode(x);
    if (*rear == nullptr) // Queue is empty
    {
        *front = *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

void dequeue(node **front, node **rear, int &x)
{
    if (*front == nullptr) // Queue is empty
    {
        cout << "Queue is empty." << endl;
        return;
    }
    node *tmp = *front;
    x = tmp->value;
    *front = (*front)->next;

    if (*front == nullptr) // If the queue becomes empty after dequeue
    {
        *rear = nullptr;
    }
    delete tmp;
}

void printQueue(node *front)
{
    if (front == nullptr)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    node *tmp = front;
    while (tmp != nullptr)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    node *front = nullptr, *rear = nullptr;
    int choice, value;

    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            enqueue(&front, &rear, value);
            cout << "Element added to the queue successfully." << endl;
            break;
        case 2:
            if (front == nullptr)
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                dequeue(&front, &rear, value);
                cout << "Element " << value << " removed from the queue successfully." << endl;
            }
            break;
        case 3:
            cout << "Printing the queue: ";
            printQueue(front);
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice. Please enter again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
