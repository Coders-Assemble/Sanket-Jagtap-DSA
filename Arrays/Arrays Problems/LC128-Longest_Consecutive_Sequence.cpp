#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force
// TC => O(n^2)
// SC => O(1)

bool ls(vector<int> &arr, int num)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size();
    int longest = 1;

    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int count = 1;

        while (ls(a, x + 1))
        {
            x = x + 1;
            count = count + 1;
        }
        longest = max(longest, count);
    }
    return longest;
}

// Better Approach
// TC => O(NlogN) + O(N)
// SC => O(1)

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int longest = 1, count = 0, lastSmaller = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] - 1 == lastSmaller)
            {
                count = count + 1;
                lastSmaller = nums[i];
            }
            else if (nums[i] != lastSmaller)
            {
                count = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, count);
        }
        return longest;
    }
};