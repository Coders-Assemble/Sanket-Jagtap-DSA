#include <iostream>
#include <vector>
using namespace std;

// TC => O(nlogn)
// SC => O(n)

class Solution
{
public:
    void preorder(vector<int> &nums, int start, int end, vector<int> &ans)
    {
        if (start > end)
            return;

        int mid = (start + end) / 2;
        ans.push_back(nums[mid]);
        preorder(nums, start, mid - 1, ans);
        preorder(nums, mid + 1, end, ans);
    }

    vector<int> sortedArrayToBST(vector<int> &nums)
    {
        vector<int> ans;
        preorder(nums, 0, nums.size() - 1, ans);
        return ans;
    }
};
