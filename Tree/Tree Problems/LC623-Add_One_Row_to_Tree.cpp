#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(1) + O(n) Auxillary Stack Space

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
    TreeNode *addRow(TreeNode *root, int val, int depth, int currDepth)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (currDepth == depth - 1)
        {
            TreeNode *leftTemp = root->left;
            TreeNode *rightTemp = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = leftTemp;
            root->right->right = rightTemp;

            return root;
        }

        root->left = addRow(root->left, val, depth, currDepth + 1);
        root->right = addRow(root->right, val, depth, currDepth + 1);

        return root;
    }

    TreeNode *addOnw(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        int currDepth = 1;
        return addRow(root, val, depth, currDepth);
    }
};