#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

// User function Template for C++
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    int Burn(Node *root, int &time, int target)
    {
        if (!root)
            return 0;

        if (root->data == target)
        {
            return -1;
        }

        int left = Burn(root->left, time, target);
        int right = Burn(root->right, time, target);

        if (left < 0)
        {
            time = max(time, abs(left) + right);
            return left - 1;
        }

        if (right < 0)
        {
            time = max(time, left + abs(right));
            return right - 1;
        }

        return 1 + (max(left, right));
    }

    void find(Node *root, int target, Node *&BurnNode)
    {
        if (!root)
            return;

        if (root->data == target)
        {
            BurnNode = root;
            return;
        }

        find(root->left, target, BurnNode);
        find(root->right, target, BurnNode);
    }

    int Height(Node *root)
    {
        if (!root)
            return 0;

        return 1 + max(Height(root->left), Height(root->right));
    }

    int minTime(Node *root, int target)
    {
        int time = 0;

        Burn(root, time, target);

        Node *BurnNode = NULL;
        find(root, target, BurnNode);

        int height = Height(BurnNode) - 1;

        return max(height, time);
    }
};
