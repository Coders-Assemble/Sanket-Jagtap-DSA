#include <iostream>
#include <vector>
#include <queue>
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

Node *BuildTree()
{
    int data;
    cout << "Enter node data: ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // Create root node
    Node *root = new Node(data);

    // root-left
    cout << "Enter data for left part of " << data << " node" << endl;
    root->left = BuildTree();

    // root-right
    cout << "Enter data for right part of " << data << " node" << endl;
    root->right = BuildTree();

    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

        cout << temp->data << " ";

        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;
    root = BuildTree();

    levelOrderTraversal(root);

    return 0;
}