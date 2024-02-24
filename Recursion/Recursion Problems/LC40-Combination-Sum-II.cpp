#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void combinationSum2_helper(vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &v, int index)
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
            if (i > index && arr[i] == arr[i - 1])
            {
                continue;
            }
            v.push_back(arr[i]);
            combinationSum2_helper(arr, target - arr[i], ans, v, i + 1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        combinationSum2_helper(candidates, target, ans, v, 0);
        return ans;
    }
};
