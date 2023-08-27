#include <iostream>
#include <limits.h>
using namespace std;

void printRowWiseSum(int arr[][3], int row, int col)
{
    cout << "Printing sum row wise" << endl;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << sum << endl;
    }
}

void printColWiseSum(int arr[3][3], int row, int col)
{
    cout << "Printing sum column wise" << endl;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum = sum + arr[j][i];
        }
        cout << sum << endl;
    }
}

bool findKey(int arr[][3], int row, int col, int key)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == key)
            {
                return true;
            }
        }
    }
    return false;
}

int getMax(int arr[][3], int row, int col)
{
    int maxi = INT_MIN;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > maxi)
                maxi = arr[i][j];
        }
    }
    return maxi;
}

int getMin(int arr[][3], int row, int col)
{
    int mini = INT_MAX;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] < mini)
                mini = arr[i][j];
        }
    }
    return mini;
}

void transpose(int arr[][3], int r, int c, int transposeArr[][3])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            transposeArr[i][j] = arr[j][i];
            // transposeArr[j][i] = arr[i][j];
        }
    }
}

void printArray(int arr[][3], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3];

    int row = 3;
    int col = 3;

    cout << "Taking input row-wise" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Printing row-wise" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // cout << "Printing column-wise" << endl;
    // for (int i = 0; i < row; i++) {
    //   for (int j = 0; j < col; j++) {
    //     cout << arr[j][i] << " ";
    //   }
    //   cout << endl;
    // }

    // printRowWiseSum(arr, row, col);
    // printColWiseSum(arr, row, col);

    // Searching
    // int key = 5;
    // if (findKey(arr, row, col, key)) {
    //   cout << "Key is present" << endl;
    // } else {
    //   cout << "Key is absent" << endl;
    // }

    // cout << "Max number is : " << getMax(arr, row, col) << endl;
    // cout << "Min number is : " << getMin(arr, row, col) << endl;

    cout << "Printing Array" << endl;
    printArray(arr, row, col);
    int transposeArr[3][3];
    cout << "Transposing........." << endl;
    transpose(arr, row, col, transposeArr);
    cout << "Printing Array Again" << endl;
    printArray(transposeArr, row, col);

    return 0;
}