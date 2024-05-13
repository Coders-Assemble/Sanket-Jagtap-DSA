#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
            return result;

        queue<TreeNode *> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while (!nodesQueue.empty())
        {
            int size = nodesQueue.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = nodesQueue.front();
                nodesQueue.pop();

                int index = leftToRight ? i : (size - 1 - i);

                row[index] = temp->val;

                if (temp->left)
                    nodesQueue.push(temp->left);
                if (temp->right)
                    nodesQueue.push(temp->right);
            }
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};