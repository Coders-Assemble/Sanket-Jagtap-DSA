#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void permuteUnique_helper(vector<int> &nums, vector<vector<int>> &ans, int start)
    {
        if (start >= nums.size())
        {
            ans.push_back(nums);
        }

        unordered_map<int, bool> visited;
        for (int i = start; i < nums.size(); i++)
        {
            if (visited.find(nums[i]) != visited.end())
            {
                continue;
            }
            visited[nums[i]] = true;
            swap(nums[i], nums[start]);
            permuteUnique_helper(nums, ans, start + 1);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        permuteUnique_helper(nums, ans, 0);
        return ans;
    }
};