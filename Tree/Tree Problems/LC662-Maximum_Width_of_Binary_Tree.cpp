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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();
            int minIndex = q.front().second;
            int first, last;

            for (int i = 0; i < size; i++)
            {
                int currIndex = q.front().second - minIndex;

                TreeNode *temp = q.front().first;
                q.pop();

                if (i == 0)
                    first = currIndex;
                if (i == size - 1)
                    last = currIndex;

                if (temp->left)
                {
                    q.push({temp->left, (long long)currIndex * 2 + 1});
                }

                if (temp->right)
                {
                    q.push({temp->right, (long long)currIndex * 2 + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};