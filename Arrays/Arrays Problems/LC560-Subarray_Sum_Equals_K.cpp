#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute Force
// TC => O(N^2)
// SC => O(1)

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            int sub_sum = 0;
            for (int j = i; j < n; j++)
            {
                sub_sum = sub_sum + nums[j];
                if (sub_sum == k)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

