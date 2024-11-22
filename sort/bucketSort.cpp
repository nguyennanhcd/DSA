#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<float>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    vector<float> b[n];

    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        insertionSort(b[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
}

int main() {
    int n;

    cout << "Nhap so luong phan tu: ";
    cin >> n;

    float* arr = new float[n];

    cout << "Nhap so luong phan tu tu 0 den 1:";
    cout<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < 0 || arr[i] > 1) {
            cout << "Hay nhap phan tu co gia tri tu 0 den 1" << endl;
            --i;
        }
    }

    bucketSort(arr, n);

    cout << "Sorted array is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
