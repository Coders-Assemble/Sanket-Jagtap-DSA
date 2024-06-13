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
    int pathSum(TreeNode *root, int &sum)
    {
        if (!root)
            return 0;

        int leftSum = max(0, pathSum(root->left, sum));
        int rightSum = max(0, pathSum(root->right, sum));

        sum = max(sum, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;

        pathSum(root, maxSum);

        return maxSum;
    }
};