#include <iostream>
using namespace std;

// Hàm hoán đổi hai phần tử
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// đảm bảo rằng thằng cha sẽ luôn lớn hơn thằng con
// ban đầu biến largest dùng để lưu vị trí của thằng có giá trị lớn nhất 
// sau khi tìm được vị trí có giá trị lớn nhất, chúng ta sẽ hoán vị giá trị của vị trí đó với largest cũ
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


// hàm heapsort sẽ heapìy khi 
// thực hiện heapify ở các phần  là lá
// sau đó nó sẽ hoán đổi phần tử đầu tiên với phần tử có vị trí cuối cùng để đẩy phần tử lớn nhất xuống vị trí cuối cùng của mảng
// và tiếp tục heapify để tiếp tục tìm nút lớn nhất
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang truoc khi sap xep: ";
    displayArray(arr, n);

    heapSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    displayArray(arr, n);

    return 0;
}
