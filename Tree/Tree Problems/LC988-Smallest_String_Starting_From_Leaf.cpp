#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(1) + O(depth) Auxillary Stack Space

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
    void dfs(TreeNode *root, string curr, string &ans)
    {
        if (root == NULL)
        {
            return;
        }

        curr = char(root->val + 'a') + curr;

        if (root->left == NULL && root->right == NULL)
        {
            if (ans == "" || ans > curr)
            {
                ans = curr;
                curr.erase(0, 1);
            }
            return;
        }

        dfs(root->left, curr, ans);
        dfs(root->right, curr, ans);
    }

    string smallestFromLeaf(TreeNode *root)
    {
        string ans = "";
        string curr = "";
        dfs(root, curr, ans);
        return ans;
    }
};