#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Approach 01
class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int s = 0;
        int e = arr.size() - 1;
        int ans = INT_MAX;

        while (s <= e)
        {
            int mid = (s + e) / 2;

            if (s == e)
            {
                if (arr[s] < ans)
                    ans = arr[s];
            }

            if (arr[mid] > arr[e])
            {
                if (arr[mid] < ans)
                {
                    ans = arr[mid];
                }
                s = mid + 1;
            }
            else
            {
                if (arr[mid] < ans)
                {
                    ans = arr[mid];
                }
                e = mid - 1;
            }
        }
        return ans;
    }
};

// Approach 02
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[low] <= nums[high])
            {
                ans = min(ans, nums[low]);
                break;
            }

            if (nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                ans = min(ans, nums[mid]);
            }
        }
        return ans;
    }
};