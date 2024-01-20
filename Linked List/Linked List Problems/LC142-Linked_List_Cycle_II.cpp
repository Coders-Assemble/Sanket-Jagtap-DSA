#include <iostream>
using namespace std;

// TC => O(n)
// SC => O(1)

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool checkForLoop(ListNode *&head)
    {
        if (head == NULL)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }

    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
            return head;

        bool ans = checkForLoop(head);
        if (ans == 0)
        {
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }

            if (slow == fast)
            {
                slow = head;
                break;
            }
        }

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};