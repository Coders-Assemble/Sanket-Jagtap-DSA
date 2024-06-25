#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1
void KSum(Node *root, int &sum, int &k)
{
    if (!root)
        return;

    KSum(root->left, sum, k);
    k--;
    if (k >= 0)
    {
        sum += root->data;
    }
    if (k <= 0)
    {
        return;
    }
    KSum(root->right, sum, k);
}

int sum(Node *root, int k)
{
    int sum = 0;
    KSum(root, sum, k);
    return sum;
}