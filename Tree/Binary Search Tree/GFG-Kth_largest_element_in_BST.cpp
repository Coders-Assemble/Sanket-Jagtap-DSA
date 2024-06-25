#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
    void KLargest(Node *root, int &ans, int &k)
    {
        if (!root)
            return;

        KLargest(root->right, ans, k);
        k--;
        if (k == 0)
        {
            ans = root->data;
            return;
        }
        KLargest(root->left, ans, k);
    }

    int kthLargest(Node *root, int K)
    {
        int ans;
        KLargest(root, ans, K);
        return ans;
    }
};