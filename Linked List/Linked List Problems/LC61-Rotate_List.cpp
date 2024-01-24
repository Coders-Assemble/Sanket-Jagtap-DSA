#include <iostream>
using namespace std;

// TC => O(n)
// SC => O(1)

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getLength(ListNode *&head)
    {
        int len = 0;
        ListNode *temp = head;

        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        int n = getLength(head);
        if (k % n == 0)
            return head;

        ListNode *temp = head;
        k %= n;
        int i = 1;

        while (i <= n - k - 1)
        {
            temp = temp->next;
            i++;
        }

        ListNode *rotateListHead = temp->next;
        temp->next = NULL;

        temp = rotateListHead;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = head;

        return rotateListHead;
    }
};