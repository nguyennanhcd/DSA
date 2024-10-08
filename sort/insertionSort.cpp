#include <iostream>
using namespace std;

// insertionSort là thuật toán tìm vị trí thích hợp của phần tử hiện tại trong mảng
void insertionSort(int arr[], int n)
{
    // so sánh với mọi phần tử bên trái của nó, nếu lớn hơn thì đẩy về bên phải
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int pos = i -1;
        while(pos >= 0 && arr[pos] > temp)
        {
            arr[pos + 1] = arr[pos];
            pos --;
        }
        arr[pos+1] = temp;
    }
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

    insertionSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    displayArray(arr, n);

    return 0;
}
