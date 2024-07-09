#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n) Auxillary Stack Space

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
    void sumOfNodes(TreeNode *root, int &low, int &high, int &sum)
    {
        if (!root)
            return;

        if (root->val > low && root->val > high)
        {
            return sumOfNodes(root->left, low, high, sum);
        }
        else if (root->val < low && root->val < high)
        {
            return sumOfNodes(root->right, low, high, sum);
        }
        else
        {
            sumOfNodes(root->left, low, high, sum);
            sum += root->val;
            sumOfNodes(root->right, low, high, sum);
        }
    }

    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int sum = 0;
        sumOfNodes(root, low, high, sum);
        return sum;
    }
};