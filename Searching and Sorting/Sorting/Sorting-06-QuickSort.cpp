#include <iostream>
#include <vector>
using namespace std;

// TC => Best and Avg case O(nlogn)
//       Worst case O(n^2)
// SC => O(1) + O(n) auxiliary stack space.

class Solution
{
public:
    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[low];
        int i = low;
        int j = high;

        while (i < j)
        {
            while (nums[i] <= pivot && i < high)
            {
                i++;
            }

            while (nums[j] > pivot && j > low)
            {
                j--;
            }

            if (i < j)
            {
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[low], nums[j]);
        return j;
    }

    void qs(vector<int> &nums, int low, int high)
    {
        if (low < high)
        {
            int partitionIndex = partition(nums, low, high);
            qs(nums, low, partitionIndex - 1);
            qs(nums, partitionIndex + 1, high);
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        qs(nums, 0, nums.size() - 1);
        return nums;
    }
};

// Approach 2

int partition(int *arr, int s, int e)
{
    int pI = s;
    int pivotElement = arr[s];

    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivotElement)
            count++;
    }

    swap(arr[pI], arr[s + count]);
    pI = s + count;

    int i = s;
    int j = e;

    while (i < pI && j > pI)
    {
        while (arr[i] <= arr[pI])
            i++;

        while (arr[j] > arr[pI])
            j--;

        if (i < pI && j > pI)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pI;
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    // Partitioning logic
    int pI = partition(arr, s, e);

    // Recursive call for left part
    quickSort(arr, s, pI - 1);

    // Recursive call for right part
    quickSort(arr, pI + 1, e);
}

int main()
{
    int input[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int n = 11;

    quickSort(input, 0, n - 1);

    cout << "Printing the sorted array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;

    return 0;
}
