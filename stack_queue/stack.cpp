#include <iostream>
using namespace std;

#define MAX 100

struct Node
{
    int data;
    struct Node *next;
};

void init(Node **top, int &num)
{
    *top = NULL;
    num = 0;
}

int push(Node **top, int &num, int x)
{
    if (num < MAX - 1)
    {
        Node *new_node = new Node;
        new_node->data = x;
        new_node->next = *top;
        *top = new_node;
        num++;
        return 1;
    }
    return 0;
}

int pop(Node **top, int &num, int &x)
{
    if (*top != NULL && num > 0)
    {
        x = (*top)->data;
        Node *temp = *top;
        *top = (*top)->next;
        delete temp;
        num--;
        return 1;
    }
    return 0;
}

int isFull(int num)
{
    if (num == MAX - 1)
        return 1;
    return 0;
}

int isEmpty(int num)
{
    if (num == 0)
        return 1;
    return 0;
}

void displayStack(Node *top)
{
    if (top == NULL)
    {
        cout << "Stack is empty.\n";
    }
    else
    {
        cout << "Stack contents:\n";
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    Node *top;
    int num;
    init(&top, num);

    int choice, value, result;

    do
    {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check if Full\n";
        cout << "4. Check if Empty\n";
        cout << "5. Display Stack\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            if (push(&top, num, value))
                cout << "Value pushed into stack.\n";
            else
                cout << "Stack is full, cannot push value.\n";
            break;
        case 2:
            if (pop(&top, num, value))
                cout << "Value popped from stack: " << value << endl;
            else
                cout << "Stack is empty, cannot pop value.\n";
            break;
        case 3:
            if (isFull(num))
                cout << "Stack is full.\n";
            else
                cout << "Stack is not full.\n";
            break;
        case 4:
            if (isEmpty(num))
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";
            break;
        case 5:
            displayStack(top);
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}
