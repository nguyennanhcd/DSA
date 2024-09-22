#include <iostream>
using namespace std;
#define MAX 100

void init(int a[], int &front, int &rear)
{
    front = -1;
    rear = -1;
}

// phương pháp tịnh tiến
int PushT(int a[], int &front, int &rear, int &size, int x)
{
    if (size == MAX) // Queue đầy
        return 0;
    if (front == -1) // Queue rỗng
        front = 0;
    if (rear == MAX - 1) // Tràn Queue
    {
        for (int i = front; i <= rear; i++)
            a[i - front] = a[i];
        rear = MAX - 1 - front;
        front = 0;
    }
    a[++rear] = x; // thêm phần tử mới và tăng rear và size lên
    size++;
    return 1;
}

int PopT(int a[], int &front, int &rear, int &x)
{
    if (front == -1) // Queue rỗng
        return 0;
    else
    {
        x = a[front++];
        if (front > rear) // trường hợp Queue có 1 phần tử
        {
            front = -1;
            rear = -1;
            // Queue hiện đang trống
        }
        return 1;
    }
}

// phuong phap vong

int Push(int a[], int &front, int &rear, int x)
{
    if ((rear - front == MAX - 1) || (rear - front == -1)) // Queue đầy
        return 0;
    else
    {
        if (front == -1) // Queue rỗng
            front = 0;
        if (rear == MAX - 1)
            rear = -1;
        a[++rear] = x;
        return 1;
    }
}

int Pop(int a[], int &front, int &rear, int &x)
{
    if (front != -1)
    {
        x = a[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
            if (front > MAX - 1)
                front = 0;
        }
        return 1;
    }
    return 0;
}

int isEmpty(int front)
{
    if (front == -1)
        return 1;
    return 0;
}

void print(int a[], int &front, int &rear)
{
    if (isEmpty(front))
        cout << "Queue is empty." << endl;
    else
    {
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}

int main()
{
    int front, rear;
    int a[MAX];
    init(a, front, rear);
    int x;
    cin >> x;
    if (Push(a, front, rear, x))
    {
        cout << "Pushed element is " << x << endl;
    }
    else
    {
        cout << "Queue is full, can't push" << endl;
    }

    // if (Pop(a, front, rear, x))
    // {
    //     cout << "Popped element is " << x << endl;
    // }
    // else
    // {
    //     cout << "Queue is empty, can't pop" << endl;
    // }

    print(a, front, rear);

    return 0;
}