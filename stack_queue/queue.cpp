#include <iostream>
#define MAX 100

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int queueSize;
struct Node *front;
struct Node *rear;

// Khởi tạo queue
void init(int &size, Node **front, Node **rear)
{
    *front = NULL;
    *rear = NULL;
    size = 0;
}

// Hàm đẩy một phần tử vào queue
int push(int x, int &size, Node **front, Node **rear)
{
    Node *temp = new Node(); // Tạo node mới
    temp->data = x;
    temp->next = NULL;

    if (*rear == NULL)
    {
        *front = *rear = temp;
    }
    else
    {
        (*rear)->next = temp;
        *rear = temp;
    }
    size++;
    return 1;
}

// Hàm lấy một phần tử ra khỏi queue
int pop(int &x, int &size, Node **front, Node **rear)
{
    if (*front == NULL)
    { // Underflow
        return 0;
    }

    Node *temp = *front;
    x = temp->data;
    *front = (*front)->next;

    if (*front == NULL)
    { // Nếu phần tử vừa pop ra là phần tử cuối cùng
        *rear = NULL;
    }

    delete temp; // Giải phóng bộ nhớ
    size--;
    return 1;
}

// Hàm kiểm tra queue có rỗng không
int isEmpty(int size)
{
    return size == 0;
}

// Hàm chính
int main()
{
    init(queueSize, &front, &rear);

    // Đẩy một số phần tử vào queue
    push(10, queueSize, &front, &rear);
    push(20, queueSize, &front, &rear);
    push(30, queueSize, &front, &rear);

    // Lấy phần tử ra khỏi queue
    int x;
    if (pop(x, queueSize, &front, &rear))
    {
        cout << "Phan tu duoc lay ra: " << x << endl;
    }
    else
    {
        cout << "Queue rong!" << endl;
    }

    // Kiểm tra xem queue có rỗng không
    if (isEmpty(queueSize))
    {
        cout << "Queue rong!" << endl;
    }
    else
    {
        cout << "Queue khong rong!" << endl;
    }

    return 0;
}
