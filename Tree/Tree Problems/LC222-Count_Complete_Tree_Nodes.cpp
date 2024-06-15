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
    void solve(TreeNode *root, int &count)
    {
        if (!root)
        {
            return;
        }

        count++;

        solve(root->left, count);
        solve(root->right, count);
    }

    int countNodes(TreeNode *root)
    {
        int count = 0;

        solve(root, count);

        return count;
    }
};

// TC => O(logn)^2
// SC => O(logn)

class Solution
{
public:
    int getLeftHeight(TreeNode *root)
    {
        TreeNode *temp = root;
        int lh = 0;

        while (temp)
        {
            temp = temp->left;
            lh++;
        }

        return lh;
    }

    int getRightHeight(TreeNode *root)
    {
        TreeNode *temp = root;
        int rh = 0;

        while (temp)
        {
            temp = temp->right;
            rh++;
        }

        return rh;
    }

    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);

        if (lh == rh)
        {
            return (pow(2, lh) - 1);
        }

        return countNodes(root->left) + 1 + countNodes(root->right);
    }
};