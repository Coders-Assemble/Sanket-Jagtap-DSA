#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        int j = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            if (j >= n)
            {
                j = 0;
            }
            ans.push_back(nums[j]);
            j++;
        }

        return ans;
    }
};

class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < 2 * n; i++)
        {
            ans.push_back(nums[i % n]);
        }

        return ans;
    }
};