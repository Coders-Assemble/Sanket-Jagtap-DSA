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
    int findLength(ListNode *&head)
    {
        int size = 0;
        ListNode *temp = head;

        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }

    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == NULL)
        {
            ListNode *temp = head;
            head = NULL;
            delete temp;
            return head;
        }

        int size = findLength(head);

        if (size % 2 == 0)
            size += 1;

        int i = 0;

        ListNode *prev = head;
        while (i < size / 2 - 1)
        {
            prev = prev->next;
            i++;
        }
        ListNode *mid = prev->next;

        prev->next = mid->next;

        mid->next = NULL;

        delete mid;

        return head;
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == NULL)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        fast = fast->next->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow->next;

        slow->next = mid->next;

        mid->next = NULL;

        delete mid;

        return head;
    }
};