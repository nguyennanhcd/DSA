#include <iostream>
using namespace std;

void inputMatrix(int **arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void printMatrix(int **arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void sortDiagonally(int **arr, int row, int col)
{
    int temp;
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < col - i - 1; j++)
        {
            if (arr[i][j] > arr[i + 1][j + 1])
            {
                temp = arr[i][j];
                arr[i][j] = arr[i + 1][j + 1];
                arr[i + 1][j + 1] = temp;
            }
        }
    }
}

int main()
{
    int row;
    int col;
    cout << "Nhap so hang cua ma tran: ";
    cin >> row;
    cout << "Nhap so cot cua ma tran: ";
    cin >> col;

    int **arr;
    arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    inputMatrix(arr, row, col);
    cout << endl;
    sortDiagonally(arr, row, col);
    printMatrix(arr, row, col);
    return 0;
}