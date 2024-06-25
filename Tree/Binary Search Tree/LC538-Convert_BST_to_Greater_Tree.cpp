#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

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
    void solve(TreeNode *root, int &prev)
    {
        if (!root)
            return;

        solve(root->right, prev);
        root->val = root->val + prev;
        prev = root->val;
        solve(root->left, prev);
    }

    TreeNode *convertBST(TreeNode *root)
    {
        int prev = 0;
        solve(root, prev);
        return root;
    }
};