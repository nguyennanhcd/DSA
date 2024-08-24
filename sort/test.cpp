#include <iostream>
using namespace std;

// void bubbleSort(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(arr[j], arr[j + 1]);
//             }
//         }
//     }
// }

// void selectionSort(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int minIndex = i;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[minIndex])
//             {
//                 minIndex = j;
//             }
//         }
//         swap(arr[i], arr[minIndex]);
//     }
// }

// void insertionSort(int arr[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         int tmp = arr[i];
//         int pos = i - 1;
//         while (pos >= 0 && arr[pos] > tmp)
//         {
//             arr[pos + 1] = arr[pos];
//             pos--;
//         }
//         arr[pos + 1] = tmp;
//     }
// }
void merge(int arr[], int l, int mid, int r)
{
}

void mergeSort(int arr[], int l, int r)
{
    if (l > r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

// Hàm hiển thị mảng
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm chính
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang truoc khi sap xep: ";
    displayArray(arr, n);

    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    mergeSort(arr, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    displayArray(arr, n);

    return 0;
}
