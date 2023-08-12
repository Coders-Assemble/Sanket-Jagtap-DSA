#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    int mid = start + ((end - start) / 2);

    while (start <= end)
    {
        int element = arr[mid];

        if (element == target)
        {
            return mid;
        }
        else if (element > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + ((end - start) / 2);
    }

    return -1;
}

int main()
{

    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    int indexOfElement = binarySearch(arr, size, target);

    if (indexOfElement == -1)
    {
        cout << "Target not found" << endl;
    }
    else
    {
        cout << "Target found at " << indexOfElement << " index" << endl;
    }

    vector<int> v{1, 2, 3, 4, 5, 6, 7};

    if (binary_search(v.begin(), v.end(), 5))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    int brr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(brr) / sizeof(brr[0]);

    if (binary_search(brr, brr + n, 70))
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}