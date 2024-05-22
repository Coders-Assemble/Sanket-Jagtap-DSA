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
            {
                return i;
            }
        }
        return -1;
    }

    TreeNode *Tree(vector<int> &in, vector<int> &post, int inStart, int inEnd, int index)
    {
        if (inStart > inEnd)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(post[index]);
        int pos = find(in, post[index], inStart, inEnd);

        // right
        root->right = Tree(in, post, pos + 1, inEnd, index - 1);

        // left
        root->left = Tree(in, post, inStart, pos - 1, index - (inEnd - pos) - 1);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return Tree(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    }
};

