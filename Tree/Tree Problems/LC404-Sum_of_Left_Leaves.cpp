#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(1) + O(d) Auxillary Stack Space

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
    int solve(TreeNode *curr, TreeNode *parent)
    {
        if (curr == NULL)
        {
            return 0;
        }

        if (curr->left == NULL && curr->right == NULL)
        {
            if (parent != NULL && parent->left == curr)
            {
                return curr->val;
            }
        }

        int left = solve(curr->left, curr);
        int right = solve(curr->right, curr);

        return left + right;
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        return solve(root, NULL);
    }
};

// TC => O(n)
// SC => O(1) + O(d) Auxillary Stack Space

class Solution
{
public:
    int solve(TreeNode *curr, bool isLeft)
    {
        if (curr == NULL)
        {
            return 0;
        }

        if (curr->left == NULL && curr->right == NULL && isLeft == true)
        {
            return curr->val;
        }

        int left = solve(curr->left, true);
        int right = solve(curr->right, false);

        return left + right;
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        return solve(root, false);
    }
};