#include <iostream>
using namespace std;
#define M 11
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

int hashFunction(int value)
{
    return value % M;
}

void initHashTable(HashTable &t)
{
    for (int i = 0; i < M; i++)
    {
        t.h[i].value = -1;
        t.h[i].next = -1;
    }

    t.r = M - 1;
}

void insertHashTable(HashTable &t, int value)
{
}

int main()
{
    return 0;
}