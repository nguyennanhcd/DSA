#include <iostream>
using namespace std;
#define MAX 100

void init(int a[], int &sp)
{
    sp = -1;
}

int push(int a[], int &sp, int x)
{
    if (sp < MAX - 1)
    {
        a[++sp] = x;
        return 1;
    }
    return 0;
}

int pop(int a[], int &sp, int &x)
{
    if (sp != -1)
    {
        x = a[sp--];
        return 1;
    }
    return 0;
}

int isFull(int a[], int sp)
{
    return (sp == MAX - 1);
}

int isEmpty(int a[], int sp)
{
    return (sp == -1);
}

void traverse(int a[], int sp)
{
    if (isEmpty(a, sp))
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Stack elements from bottom to top:" << endl;
    for (int i = 0; i <= sp; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[MAX];
    int sp;
    init(a, sp);

    int choice, x;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check if Full\n";
        cout << "4. Check if Empty\n";
        cout << "5. Traverse Stack\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> x;
            if (push(a, sp, x))
                cout << "Pushed " << x << " into the stack.\n";
            else
                cout << "Stack is full, cannot push.\n";
            break;
        case 2:
            if (pop(a, sp, x))
                cout << "Popped " << x << " from the stack.\n";
            else
                cout << "Stack is empty, cannot pop.\n";
            break;
        case 3:
            if (isFull(a, sp))
                cout << "Stack is full.\n";
            else
                cout << "Stack is not full.\n";
            break;
        case 4:
            if (isEmpty(a, sp))
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";
            break;
        case 5:
            traverse(a, sp);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
