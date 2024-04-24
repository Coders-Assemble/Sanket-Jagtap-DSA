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

    Node *temp = new Node(x);

    cout << "Enter the left child of " << x << " : ";
    temp->left = buildTree();
    cout << "Enter the right child of " << x << " : ";
    temp->right = buildTree();

    return temp;
}

int main()
{

    Node *root;
    cout << "Enter the root element: ";
    root = buildTree();

    return 0;
}