#include <iostream>
using namespace std;

#define M 100
struct Node
{
    int key;
    int next;
};
Node T[M];
int r = M - 1;

void init()
{
    for (int i = 0; i < M; i++)
    {
        T[i].key = -1;
        T[i].next = -1;
    }
}

// khởi tạo hàm băm
int h(int x)
{
    return (x % 10);
}

int insert(int x)
{
    int i, j;
    i = h(x);
    if ((T[i].key != x) && (T[i].key != -1))
    {
        do
        {
            j = i;
            i = T[i].next;
        } while ((T[i].key != x) && (i != -1));
        if (i == -1)
        {
            while (r != -1 && T[r].key != -1)
            {
                r--;
            }
            if (r < 10)
            {
                return -1;
            }
            if (r != -1)
            {
                T[j].next = r;
            }
            i = r;
        }
    }
    if (i != -1 && T[i].key != x)
    {
        T[i].key = x;
    }
    return i;
}

int search(int x)
{
    int i = h(x);
    while (x != T[i].key && i != -1)
    {
        i = T[i].next;
    }
    if (x == T[i].key)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int del(int x)
{
    int i = h(x), prev = i;
    while (x != T[T[i].next].key && i != -1)
    {
        if (x == T[i].key)
            break;
        prev = i;
        i = T[i].next;
    }
    if (x == T[i].key)
    { // trường hợp 1
        do
        {
            T[i].key = T[T[i].next].key;
            // dịch các node trong chain lên vị
            // trí của node cần xóa
            prev = i;
            i = T[i].next;
        } while (T[i].next != -1);
        T[i].key = -1;
        T[prev].next = -1;
        return 1;
    }
    else if (x == T[T[i].next].key &&
             T[T[i].next].next == -1)
    {                          // trường hợp 2
        T[T[i].next].key = -1; // cập nhật lại giá
                               // trị key của node cần xóa
        T[i]
            .next = -1; // cập nhật lại giá trị
        // next của node kế node cần xóa return 1;
    }
    else if (x == T[T[i].next].key &&
             T[T[i].next].next != -1)
    { // trường hợp 3
        int next_mapping = T[T[i].next].next;
        T[T[i].next].key = -1;
        T[T[i].next].next = -1;
        T[i].next = next_mapping;
        // gán vùng next của node cần xóa cho vùng
        // next của node kế node cần xóa
        T[T[i].next]
            .next = -1;
        return 1;
    }
    return -1; // không tìm được node có giá trị cần xóa
}

int main()
{
    return 0;
}