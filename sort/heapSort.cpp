#include <iostream>
using namespace std;

// Hàm hoán đổi hai phần tử
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Hàm xây dựng heap từ mảng
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Khởi tạo largest là root
    int left = 2 * i + 1;  // Chỉ số của con trái
    int right = 2 * i + 2; // Chỉ số của con phải

    // Nếu con trái lớn hơn root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Nếu con phải lớn hơn largest hiện tại
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Nếu largest không phải là root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Đệ quy heapify phần cây bị ảnh hưởng
        heapify(arr, n, largest);
    }
}

// Hàm thực hiện Heap Sort
void heapSort(int arr[], int n)
{
    // Xây dựng heap (rearrange array)
    // gọi heapify tới tất cả các node không phải là node lá
    // bởi vì các node lá sẽ nằm ở nửa sau của mảng
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Trích xuất từng phần tử một từ heap
    // sau khi tạo mảng hiện tại thành 1 max heap rồi thì phần tử đầu tiên sẽ là phần tử lớn nhất
    // vậy nên chúng ta sẽ đẩy phần từ lớn nhất đó ra cuối mảng và gọi hàm heapify
    for (int i = n - 1; i > 0; i--)
    {
        // Di chuyển root hiện tại đến cuối
        swap(arr[0], arr[i]);

        // Gọi heapify lên heap đã giảm
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
