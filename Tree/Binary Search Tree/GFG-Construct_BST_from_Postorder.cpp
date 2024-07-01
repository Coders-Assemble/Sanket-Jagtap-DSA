#include <iostream>
#include <vector>
using namespace std;

// TC => O(N)
// SC => O(N)

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *BST(int post[], int &index, int lower, int upper)
{
    if (index < 0 || post[index] < lower || post[index] > upper)
        return NULL;

    Node *root = new Node(post[index--]);
    root->right = BST(post, index, root->data, upper);
    root->left = BST(post, index, lower, root->data);

    return root;
}

Node *constructTree(int post[], int size)
{
    int index = size - 1;
    return BST(post, index, INT_MIN, INT_MAX);
}