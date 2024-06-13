#include <iostream>
#include <vector>
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

class Solution
{
public:
    int pathSum(Node *root, int &sum)
    {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return root->data;

        int left = pathSum(root->left, sum);
        int right = pathSum(root->right, sum);

        if (root->left && root->right)
        {
            sum = max(sum, root->data + left + right);
            return root->data + max(left, right);
        }

        if (root->left)
        {
            return root->data + left;
        }

        if (root->right)
        {
            return root->data + right;
        }
    }

    int maxPathSum(Node *root)
    {
        int sum = INT_MIN;

        int val = pathSum(root, sum);

        if (root->left && root->right)
        {
            return sum;
        }

        return max(sum, val);
    }
};