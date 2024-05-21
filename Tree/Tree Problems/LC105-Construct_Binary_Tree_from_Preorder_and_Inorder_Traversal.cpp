#include <iostream>
#include <vector>
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