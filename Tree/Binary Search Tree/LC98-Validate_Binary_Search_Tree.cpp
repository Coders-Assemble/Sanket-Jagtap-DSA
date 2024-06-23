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
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool isValidBST(TreeNode *root)
    {
        vector<int> ans;
        inorder(root, ans);

        for (int i = 1; i < ans.size(); i++)
        {
            if (ans[i] <= ans[i - 1])
            {
                return false;
            }
        }

        return true;
    }
};

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    bool checkBST(TreeNode *root, long &prev)
    {
        if (!root)
            return true;

        if (checkBST(root->left, prev) == false)
        {
            return false;
        }

        if (root->val <= prev)
        {
            return false;
        }

        prev = root->val;

        return checkBST(root->right, prev);
    }

    bool isValidBST(TreeNode *root)
    {
        long prev = LONG_MIN;

        return checkBST(root, prev);
    }
};
