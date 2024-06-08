#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    Node *findBurnNodeAndMakeMapping(Node *root, unordered_map<Node *, Node *> &parentMap, int target)
    {
        queue<Node *> q;
        q.push(root);
        Node *BurnNode = NULL;

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp->data == target)
                BurnNode = temp;

            if (temp->left)
            {
                parentMap[temp->left] = temp;
                q.push(temp->left);
            }

            if (temp->right)
            {
                parentMap[temp->right] = temp;
                q.push(temp->right);
            }
        }

        return BurnNode;
    }

    int BurnTree(Node *BurnNode, unordered_map<Node *, Node *> &parentMap)
    {
        unordered_map<Node *, bool> isAlreadyBurned;
        queue<Node *> q;
        q.push(BurnNode);
        isAlreadyBurned[BurnNode] = true;
        int time = 0;

        while (!q.empty())
        {
            int size = q.size();
            bool isBurnSpreaded = false;
            for (int i = 0; i < size; i++)
            {
                Node *temp = q.front();
                q.pop();

                if (temp->left && !isAlreadyBurned[temp->left])
                {
                    q.push(temp->left);
                    isAlreadyBurned[temp->left] = true;
                    isBurnSpreaded = true;
                }

                if (temp->right && !isAlreadyBurned[temp->right])
                {
                    q.push(temp->right);
                    isAlreadyBurned[temp->right] = true;
                    isBurnSpreaded = true;
                }

                if (parentMap[temp] && !isAlreadyBurned[parentMap[temp]])
                {
                    q.push(parentMap[temp]);
                    isAlreadyBurned[parentMap[temp]] = true;
                    isBurnSpreaded = true;
                }
            }
            if (isBurnSpreaded)
                time++;
        }
        return time;
    }

    int minTime(Node *root, int target)
    {
        unordered_map<Node *, Node *> parentMap;                              // Node to parent mapping
        Node *BurnNode = findBurnNodeAndMakeMapping(root, parentMap, target); // return the address of target node

        return BurnTree(BurnNode, parentMap);
    }
};
