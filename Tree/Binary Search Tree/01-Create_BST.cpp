#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertNode(Node *root, int target)
{
    if (!root)
    {
        Node *temp = new Node(target);
        return temp;
    }

    if (target < root->data)
    {
        root->left = insertNode(root->left, target);
    }
    else
    {
        root->right = insertNode(root->right, target);
    }

    return root;
}

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};

    Node *root = NULL;

    for (int i = 0; i < 10; i++)
    {
        root = insertNode(root, arr[i]);
    }

    inorder(root);

    return 0;
}