#include <iostream>
#include <unordered_map>
using namespace std;

// TC => O(n)
// SC => O(n)

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;
        unordered_map<Node *, Node *> mpp;

        while (temp != NULL)
        {
            Node *newNode = new Node(temp->val);
            mpp[temp] = newNode;
            temp = temp->next;
        }

        temp = head;
        while (temp != NULL)
        {
            Node *copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];
            copyNode->random = mpp[temp->random];
            temp = temp->next;
        }

        return mpp[head];
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            Node *copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }

        temp = head;

        while (temp != NULL)
        {
            Node *copyNode = temp->next;
            if (temp->random)
            {
                copyNode->random = temp->random->next;
            }
            else
            {
                copyNode->random = NULL;
            }
            temp = temp->next->next;
        }

        temp = head;
        Node *dummyNode = new Node(-1);
        Node *res = dummyNode;

        while (temp != NULL)
        {
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }

        return dummyNode->next;
    }
};