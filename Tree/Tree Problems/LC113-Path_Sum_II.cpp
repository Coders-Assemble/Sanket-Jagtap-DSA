#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void solve(TreeNode *root, int sum, vector<vector<int>> &ans, vector<int> &path)
    {
        if (!root)
            return;

        sum -= root->val;
        path.push_back(root->val);

        if (sum == 0 && (!root->left && !root->right))
        {
            ans.push_back(path);
        }

        solve(root->left, sum, ans, path);
        solve(root->right, sum, ans, path);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root, targetSum, ans, path);
        return ans;
    }
};