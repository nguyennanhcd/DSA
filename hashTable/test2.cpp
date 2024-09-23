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
    Item heads[M];
    int r;
};

void initHashTable(HashTable &t)
{
    for (int i = 0; i < M; i++)
    {
        t.heads[i].value = -1;
        t.heads[i].next = -1;
    }
    t.r = M - 1;
}

int hashFunction(int value)
{
    return value % M;
}

void insertHashTable(HashTable &t, int value)
{
    if (t.r >= 0)
    {
        int h = hashFunction(value);
        if (t.heads[h].value == -1)
        {
            t.heads[h].value = value;
        }
        else
        {
            t.heads[t.r].value = value;
        }
    }
}

int main()
{
    return 0;
}