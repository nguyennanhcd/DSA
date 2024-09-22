#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void interchangeSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int tmp = arr[i];
        int pos = i - 1;
        while (pos >= 0 && arr[pos] > tmp)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        // pos là i - 1 nên phải cộng thêm 1 vô
        swap(arr[pos + 1], tmp);
    }
}

void merge(int arr[], int l, int mid, int r)
{
}

void mergeSort(int arr[], int l, int r)
{

    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang truoc khi sap xep: ";
    displayArray(arr, n);

    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    interchangeSort(arr, n);
    // insertionSort(arr, n);
    // mergeSort(arr, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    displayArray(arr, n);

    return 0;
}
