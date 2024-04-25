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

Node *buildTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node *newNode = new Node(x);

    // Left subtree
    cout << "Enter the left child of " << x << " : ";
    newNode->left = buildTree();

    // Right subtree
    cout << "Enter the right child of " << x << " : ";
    newNode->right = buildTree();
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    // Node
    cout << root->data << " ";
    // Left
    preOrder(root->left);
    // Right
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    // Left
    inOrder(root->left);
    // Node
    cout << root->data << " ";
    // Right
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    // Left
    postOrder(root->left);
    // Right
    preOrder(root->right);
    // Node
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    cout << "Enter the root node: ";
    root = buildTree();

    cout << endl
         << "PREORDER: ";
    preOrder(root);

    cout << endl
         << "INORDER: ";
    inOrder(root);

    cout << endl
         << "POSTORDER: ";
    postOrder(root);

    return 0;
}