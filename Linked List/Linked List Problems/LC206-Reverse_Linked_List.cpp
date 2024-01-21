#include <iostream>
using namespace std;

// TC => O(N)
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *left = NULL;
        ListNode *curr = head;
        ListNode *right = curr->next;

        while (curr != NULL)
        {
            right = curr->next;
            curr->next = left;
            left = curr;
            curr = right;
        }

        return left;
    }
};

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    ListNode *reverseUsingRecursion(ListNode *left, ListNode *curr)
    {
        if (curr == NULL)
            return left;

        ListNode *right = curr->next;
        curr->next = left;

        return reverseUsingRecursion(curr, right);
    }

    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *left = NULL;
        ListNode *curr = head;

        return reverseUsingRecursion(left, curr);
    }
};