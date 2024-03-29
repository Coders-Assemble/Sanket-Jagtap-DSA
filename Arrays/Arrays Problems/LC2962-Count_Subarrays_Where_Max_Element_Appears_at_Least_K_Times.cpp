#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxE = *max_element(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0, j = 0, countMax = 0;
        long long ans = 0;

        while (j < n)
        {
            if (nums[j] == maxE)
            {
                countMax++;
            }

            while (countMax >= k)
            {
                ans += n - j;

                if (nums[i] == maxE)
                {
                    countMax--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};