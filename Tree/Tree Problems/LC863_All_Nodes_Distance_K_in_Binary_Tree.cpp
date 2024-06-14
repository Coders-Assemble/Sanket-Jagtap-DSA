#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// TC => O(n)
// SC => O(n)

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void createChildToParentMapping(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &childParentMap)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
                childParentMap[temp->left] = temp;
            }

            if (temp->right)
            {
                q.push(temp->right);
                childParentMap[temp->right] = temp;
            }
        }
    }

    vector<int> solve(TreeNode *targetNode, unordered_map<TreeNode *, TreeNode *> &childParentMap, int k)
    {
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(targetNode);
        visited[targetNode] = true;
        int d = 0;

        while (!q.empty())
        {
            int size = q.size();
            if (d == k)
                break;
            d++;

            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (temp->left && !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }

                if (temp->right && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }

                if (childParentMap[temp] && !visited[childParentMap[temp]])
                {
                    q.push(childParentMap[temp]);
                    visited[childParentMap[temp]] = true;
                }
            }
        }

        vector<int> ans;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }

        return ans;
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> childParentMap;
        createChildToParentMapping(root, childParentMap);
        return solve(target, childParentMap, k);
    }
};