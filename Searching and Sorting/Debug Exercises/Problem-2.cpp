#include <iostream>
using namespace std;

int ceilIndex(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    int ceil = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
        {
            ceil = mid;
            right = mid - 1;
        }
    }

    return ceil;
}

int main()
{

    int arr[] = {2, 4, 6, 8, 10, 15};
    int n = 6;
    int target = 15;

    cout << "Ans is: " << ceilIndex(arr, n, target) << endl;
    return 0;
}