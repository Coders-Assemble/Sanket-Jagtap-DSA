#include <iostream>
#include <vector>
using namespace std;

// Brute Force
// TC => O(n^2)
// SC => O(1)

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxi = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum = sum + nums[j];

                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};

// Optimal approach - Kadane's Algorithm
// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxi = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];

            maxi = max(maxi, sum);

            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};