#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// TC => O(n^2)
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
    int find(vector<int> &in, int target, int start, int end)
    {
        for (int i = start; i <= end; i++)
        {
            if (in[i] == target)
                return i;
        }
        return -1;
    }

    TreeNode *Tree(vector<int> &pre, vector<int> &in, int inStart, int inEnd, int index)
    {
        if (inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(pre[index]);

        int pos = find(in, pre[index], inStart, inEnd);

        root->left = Tree(pre, in, inStart, pos - 1, index + 1);
        root->right = Tree(pre, in, pos + 1, inEnd, index + (pos - inStart) + 1);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return Tree(preorder, inorder, 0, preorder.size() - 1, 0);
    }
};

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    TreeNode *Tree(vector<int> &pre, vector<int> &in, int inStart, int inEnd, int index, unordered_map<int, int> &mpp)
    {
        if (inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(pre[index]);

        int pos = mpp[pre[index]];

        root->left = Tree(pre, in, inStart, pos - 1, index + 1, mpp);
        root->right = Tree(pre, in, pos + 1, inEnd, index + (pos - inStart) + 1, mpp);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mpp;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            mpp[inorder[i]] = i;
        }

        return Tree(preorder, inorder, 0, n - 1, 0, mpp);
    }
};