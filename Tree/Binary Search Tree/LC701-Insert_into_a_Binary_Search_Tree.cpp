#include <iostream>
#include <vector>
using namespace std;

// TC => In average case O(logn) In worst case O(n)
// SC => In average case O(logn) In worst case O(n)

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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
        {
            TreeNode *temp = new TreeNode(val);
            return temp;
        }

        if (root->val > val)
        {
            root->left = insertIntoBST(root->left, val);
            return root;
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
            return root;
        }
    }
};

// TC => In average case O(logn) In worst case O(n)
// SC => O(1)

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);

        TreeNode *curr = root;

        while (true)
        {
            if (curr->val < val)
            {
                if (curr->right != NULL)
                    curr = curr->right;
                else
                {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if (curr->left != NULL)
                    curr = curr->left;
                else
                {
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};