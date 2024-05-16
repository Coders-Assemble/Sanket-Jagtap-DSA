#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TC => O(n)
// SC => O(n)

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    void findLeftRightPos(Node *root, int pos, int &left, int &right)
    {
        if (!root)
            return;

        left = min(left, pos);
        right = max(right, pos);

        findLeftRightPos(root->left, pos - 1, left, right);
        findLeftRightPos(root->right, pos + 1, left, right);
    }

    vector<int> topView(Node *root)
    {
        int left = 0, right = 0;
        findLeftRightPos(root, 0, left, right);

        vector<int> ans(right - left + 1);
        vector<bool> visited(right - left + 1, 0);

        queue<Node *> q;
        queue<int> index;

        q.push(root);
        index.push(-1 * left);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();

            if (visited[pos] == 0)
            {
                visited[pos] = 1;
                ans[pos] = temp->data;
            }

            if (temp->left)
            {
                q.push(temp->left);
                index.push(pos - 1);
            }

            if (temp->right)
            {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }
        return ans;
    }
};