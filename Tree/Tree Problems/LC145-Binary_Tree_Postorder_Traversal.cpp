#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// TC = > O(n)
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
    void postOrder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        // Left
        postOrder(root->left, ans);
        // Right
        postOrder(root->right, ans);
        // Node
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
};

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *temp = s.top();
            s.pop();

            ans.push_back(temp->val);

            if (temp->left)
                s.push(temp->left);
            if (temp->right)
                s.push(temp->right);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};