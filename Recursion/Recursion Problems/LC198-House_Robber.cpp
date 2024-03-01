#include <iostream>
#include <vector>
using namespace std;

// TLE
// TC => O(2^n)
// SC => O(n) Auxillary stack space

class Solution
{
public:
    int rob_helper(vector<int> &nums, int i)
    {
        if (i >= nums.size())
        {
            return 0;
        }

        int robamt1 = nums[i] + rob_helper(nums, i + 2);
        int robamt2 = 0 + rob_helper(nums, i + 1);

        return max(robamt1, robamt2);
    }

    int rob(vector<int> &nums)
    {
        return rob_helper(nums, 0);
    }
};