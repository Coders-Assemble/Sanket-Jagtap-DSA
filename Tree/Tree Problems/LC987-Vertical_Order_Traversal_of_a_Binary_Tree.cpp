#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

// TC => O(nlogn)
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode *, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *temp = p.first;
            auto coordinates = p.second;
            int row = coordinates.first;
            int col = coordinates.second;

            mpp[col][row].insert(temp->val);

            if (temp->left)
            {
                q.push({temp->left, {row + 1, col - 1}});
            }

            if (temp->right)
            {
                q.push({temp->right, {row + 1, col + 1}});
            }
        }

        vector<vector<int>> ans;
        for (auto p : mpp)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};