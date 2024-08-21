#include <iostream>
using namespace std;
#define MAX 100

struct node
{
    int value;
    node *next;
};

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
    if (sp == MAX - 1)
        return 1;
    return 0;
}

int isEmpty(int a[], int sp)
{
    if (sp == -1)
        return 1;
    return 0;
}

void traverse(int a[], int sp)
{
    if (sp == -1)
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
    return 0;
}