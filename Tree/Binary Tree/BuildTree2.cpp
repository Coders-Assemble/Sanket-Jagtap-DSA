#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

int main()
{
    int x;
    int leftData, rightData;
    queue<Node *> q;

    cout << "Enter the root element: ";
    cin >> x;

    Node *root = new Node(x);

    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter the left child of " << temp->data << " : ";
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter the right child of " << temp->data << " : ";
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }

    return 0;
}