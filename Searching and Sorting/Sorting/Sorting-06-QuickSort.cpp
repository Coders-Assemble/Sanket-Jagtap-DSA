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
