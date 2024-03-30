#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    int slidingWindow(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;

        int n = nums.size();
        int i = 0, j = 0, count = 0;

        while (j < n)
        {
            mpp[nums[j]]++;

            while (mpp.size() > k)
            {
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0)
                {
                    mpp.erase(nums[i]);
                }
                i++;
            }

            count += j - i + 1;
            j++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }
};