#include <iostream>
#include <vector>
using namespace std;

// Approach 01
class Solution
{
public:
    int findPivotIndex(vector<int> arr)
    {
        int start = 0;
        int end = arr.size() - 1;
        int mid;

        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (start == end)
            {
                return start;
            }

            if ((mid + 1 <= end) && (arr[mid] > arr[mid + 1]))
            {
                return mid;
            }

            if ((mid - 1 >= start) && (arr[mid - 1] > arr[mid]))
            {
                return mid - 1;
            }

            if (arr[start] > arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }

    int binarySearch(vector<int> arr, int start, int end, int target)
    {
        int mid;

        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int pivotIndex = findPivotIndex(nums);
        int ans = 0;

        if (target >= nums[0] && target <= nums[pivotIndex])
        {
            ans = binarySearch(nums, 0, pivotIndex, target);
        }
        else
        {
            ans = binarySearch(nums, pivotIndex + 1, nums.size() - 1, target);
        }

        return ans;
    }
};

// Approach 02
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            if (target >= nums[0] && nums[mid] < nums[0])
            {
                end = mid - 1;
            }
            else if (target < nums[0] && nums[mid] >= nums[0])
            {
                start = mid + 1;
            }
            else
            {
                if (target > nums[mid])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

// Approach 03
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};