#include <iostream>
#include <vector>
using namespace std;

// Time complexity: O(nlogn)
// Space complexity: O(n)

class Solution
{
public:
    void merge(int arr[], int low, int mid, int high)
    {
        vector<int> temp(high - low + 1);
        int left = low;
        int right = mid + 1;
        int index = 0;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp[index] = arr[left];
                left++, index++;
            }
            else
            {
                temp[index] = arr[right];
                right++, index++;
            }
        }

        while (left <= mid)
        {
            temp[index] = arr[left];
            left++, index++;
        }

        while (right <= high)
        {
            temp[index] = arr[right];
            right++, index++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
};

// Approach 2

void merge(int *arr, int start, int mid, int end)
{
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    int k = start;

    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start;

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else
        {
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }

    while (leftIndex < len1)
    {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    while (rightIndex < len2)
    {
        arr[mainArrayIndex++] = right[rightIndex++];
    }
}

void mergeSort(int *arr, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{

    int arr[] = {10, 8, 9, 5, 4, 6};
    int n = 6;
    int start = 0;
    int end = n - 1;

    mergeSort(arr, start, end);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
