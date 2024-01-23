#include <iostream>
using namespace std;

// TC => O(n + m)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA;
        ListNode *b = headB;

        while (a->next && b->next)
        {
            if (a == b)
            {
                return a;
            }

            a = a->next;
            b = b->next;
        }

        if (a->next == NULL && b->next == NULL && a != b)
            return NULL;

        if (a->next == NULL)
        {
            int blen = 0;

            while (b->next != NULL)
            {
                blen++;
                b = b->next;
            }

            while (blen--)
            {
                headB = headB->next;
            }
        }
        else
        {
            int alen = 0;

            while (a->next != NULL)
            {
                alen++;
                a = a->next;
            }

            while (alen--)
            {
                headA = headA->next;
            }
        }

        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

// TC => O(n + m)
// SC => O(1)

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode *temp1 = headA;
        ListNode *temp2 = headB;

        while (temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;

            if (temp1 == temp2)
                return temp1;

            if (temp1 == NULL)
                temp1 = headB;
            if (temp2 == NULL)
                temp2 = headA;
        }

        return temp1;
    }
};