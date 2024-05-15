#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TC => O(n)
// SC => O(n)

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        int n = q.size();

        while (n--)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }

    return ans;
}

// TC => O(n)
// SC => O(n)

void Lview(Node *root, int level, vector<int> &ans)
{
    if (!root)
        return;

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    Lview(root->left, level + 1, ans);
    Lview(root->right, level + 1, ans);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    Lview(root, 0, ans);

    return ans;
}