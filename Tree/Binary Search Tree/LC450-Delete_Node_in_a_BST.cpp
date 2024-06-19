#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(h), where h is the height of the tree. This can be O(log n) for a balanced tree and O(n) for a skewed tree.
// Space Complexity: O(h), where h is the height of the tree. This can be O(log n) for a balanced tree and O(n) for a skewed tree.

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
    TreeNode *deleteNode(TreeNode *root, int target)
    {
        if (!root)
            return NULL;

        if (root->val > target)
        {
            root->left = deleteNode(root->left, target);
            return root;
        }
        else if (root->val < target)
        {
            root->right = deleteNode(root->right, target);
            return root;
        }
        else
        {
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            else if (!root->left && root->right)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->left && !root->right)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                TreeNode *parent = root;
                TreeNode *child = root->left;

                while (child->right)
                {
                    parent = child;
                    child = child->right;
                }

                if (parent != root)
                {
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }
                else
                {
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }
    }
};