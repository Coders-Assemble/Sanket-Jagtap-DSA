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
    void inOrder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        // Left
        inOrder(root->left, ans);
        // Node
        ans.push_back(root->val);
        // Right
        inOrder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inOrder(root, ans);
        return ans;
    }
};

// Iterative approach
// TC => O(n)
// SC => O(n)

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        stack<bool> visited;
        vector<int> ans;

        if (root == NULL)
            return ans;

        s.push(root);
        visited.push(0);

        while (!s.empty())
        {
            TreeNode *temp = s.top();
            s.pop();

            bool flag = visited.top();
            visited.pop();

            if (flag == 0)
            {
                if (temp->right)
                {
                    s.push(temp->right);
                    visited.push(0);
                }

                s.push(temp);
                visited.push(1);

                if (temp->left)
                {
                    s.push(temp->left);
                    visited.push(0);
                }
            }
            else
            {
                ans.push_back(temp->val);
            }
        }
        return ans;
    }
};

// Morris Inorder Traversal
// TC => O(n)
// SC => O(1)

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *pred = curr->left;
                while (pred->right != curr && pred->right != NULL)
                {
                    pred = pred->right;
                }

                if (pred->right == NULL)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};