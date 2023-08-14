#include <iostream>
using namespace std;

bool binarySearch2DMatrix(int arr[5][4], int row, int col, int target)
{
    int start = 0;
    int end = row * col - 1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        int rowIndex = mid / col;
        int colIndex = mid % col;

        if (arr[rowIndex][colIndex] == target)
        {
            return true;
        }

        if (arr[rowIndex][colIndex] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return false;
}

int main()
{

    int arr[5][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 16}, {17, 18, 19, 20}};

    int row = 5;
    int col = 4;
    int target = 19;

    bool ans = binarySearch2DMatrix(arr, row, col, target);

    if (ans)
    {
        cout << "Element Found" << endl;
    }
    else
    {
        cout << "Element not Found" << endl;
    }

    return 0;
}