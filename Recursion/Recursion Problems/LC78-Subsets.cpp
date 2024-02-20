#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve(vector<int> arr, vector<int> temp, int i, vector<vector<int>> &ans)
    {
        if (i == arr.size())
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(arr[i]);
        solve(arr, temp, i + 1, ans);
        temp.pop_back();
        solve(arr, temp, i + 1, ans);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, temp, 0, ans);
        return ans;
    }
};