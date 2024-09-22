#include <iostream>
using namespace std;

#define MAX 100

void init(int a[], int &sp)
{
    sp = -1;
}

int push(int a[], int &sp, int value)
{
    if (sp < MAX)
    {
        a[++sp] = value;
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

int main()
{
    int a[MAX];
    int sp;
    return 0;
}