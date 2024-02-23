#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void combinationSum_helper(vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &v, int index)
    {
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }

        if (target < 0)
        {
            return;
        }

        for (int i = index; i < arr.size(); i++)
        {
            v.push_back(arr[i]);
            combinationSum_helper(arr, target - arr[i], ans, v, i);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        combinationSum_helper(candidates, target, ans, v, 0);
        return ans;
    }
};

class Solution
{
public:
    void findCombinations(vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &v, int index)
    {
        if (index == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(v);
            }
            return;
        }

        if (arr[index] <= target)
        {
            v.push_back(arr[index]);
            findCombinations(arr, target - arr[index], ans, v, index);
            v.pop_back();
        }

        findCombinations(arr, target, ans, v, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        findCombinations(candidates, target, ans, v, 0);
        return ans;
    }
};