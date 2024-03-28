#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> mpp;

        int i = 0, j = 0, maxLen = 0;

        while (j < n)
        {
            mpp[nums[j]]++;

            while (i < j && mpp[nums[j]] > k)
            {
                mpp[nums[i]]--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};