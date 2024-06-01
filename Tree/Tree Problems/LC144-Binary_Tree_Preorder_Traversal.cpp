#include <iostream>
#include <vector>
#include <stack>
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
    void preOrder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preOrder(root, ans);
        return ans;
    }
};

// Iterative
// TC => O(n)
// SC => O(n)

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> ans;
        if (root == NULL)
            return ans;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *temp = s.top();
            s.pop();

            ans.push_back(temp->val);

            if (temp->right)
                s.push(temp->right);
            if (temp->left)
                s.push(temp->left);
        }

        return ans;
    }
};

// Morris Preorder Traversal
// TC => O(n)
// SC => O(1)

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *curr = root;

        while (curr)
        {
            if (curr->left == NULL)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *pred = curr->left;
                while (pred->right != NULL && pred->right != curr)
                {
                    pred = pred->right;
                }

                if (pred->right == NULL)
                {
                    ans.push_back(curr->val);
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};