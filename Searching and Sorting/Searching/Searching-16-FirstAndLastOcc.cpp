#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lowerBound(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                e = mid - 1;
            }
            else if (nums[mid] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                s = mid + 1;
            }
            else if (nums[mid] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        int ans1 = lowerBound(nums, target);
        int ans2 = upperBound(nums, target);

        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};