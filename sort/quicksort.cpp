#include <iostream>
using namespace std;

void populateArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int partition(int *arr, int l, int r)
{
    int pivot = arr[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int i = partition(arr, l, r);
        quickSort(arr, l, i - 1);
        quickSort(arr, i, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    populateArray(arr, n);
    quickSort(arr, 0, n - 1);
    print(arr, n);
    return 0;
}
