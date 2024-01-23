#include <iostream>
using namespace std;

// TC => O(n)
// SC => O(1)

// Node is defined as
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *zeroHead = new Node(-1);
        Node *zeroTail = zeroHead;

        Node *oneHead = new Node(-1);
        Node *oneTail = oneHead;

        Node *twoHead = new Node(-1);
        Node *twoTail = twoHead;

        while (head != NULL)
        {
            if (head->data == 0)
            {
                Node *temp = head;
                head = head->next;
                temp->next = NULL;

                zeroTail->next = temp;
                zeroTail = temp;
            }
            else if (head->data == 1)
            {
                Node *temp = head;
                head = head->next;
                temp->next = NULL;

                oneTail->next = temp;
                oneTail = temp;
            }
            else if (head->data == 2)
            {
                Node *temp = head;
                head = head->next;
                temp->next = NULL;

                twoTail->next = temp;
                twoTail = temp;
            }
        }

        if (oneHead->next != NULL)
        {
            Node *temp1 = oneHead;
            oneHead = oneHead->next;
            temp1->next = NULL;
            delete temp1;
            zeroTail->next = oneHead;

            if (twoHead->next != NULL)
            {
                Node *temp2 = twoHead;
                twoHead = twoHead->next;
                temp2->next = NULL;
                delete temp2;
                oneTail->next = twoHead;
            }
        }
        else
        {
            if (twoHead->next != NULL)
            {
                Node *temp2 = twoHead;
                twoHead = twoHead->next;
                temp2->next = NULL;
                delete temp2;
                zeroTail->next = twoHead;
            }
        }

        Node *temp = zeroHead;
        zeroHead = zeroHead->next;
        temp->next = NULL;
        delete temp;

        return zeroHead;
    }
};
