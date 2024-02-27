#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void permute_helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &v, vector<int> freq)
    {
        if (v.size() == nums.size())
        {
            ans.push_back(v);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                v.push_back(nums[i]);
                freq[i] = 1;
                permute_helper(nums, ans, v, freq);
                freq[i] = 0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> v;
        int n = nums.size();
        vector<int> freq(n, 0);
        permute_helper(nums, ans, v, freq);
        return ans;
    }
};

class Solution
{
public:
    void permute_helper(int ind, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[ind], nums[i]);
            permute_helper(ind + 1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        permute_helper(0, nums, ans);
        return ans;
    }
};