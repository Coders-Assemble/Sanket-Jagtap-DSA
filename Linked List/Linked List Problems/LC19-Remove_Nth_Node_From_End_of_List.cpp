#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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
        ListNode *temp = head;
        int len = 0;

        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }

        return len;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = findLength(head);

        if (n > size)
        {
            return head;
        }

        if (n == size)
        {
            ListNode *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return head;
        }

        int i = 0;
        ListNode *prev = head;
        while (i < size - n - 1)
        {
            prev = prev->next;
            i++;
        }
        ListNode *curr = prev->next;

        prev->next = curr->next;

        curr->next = NULL;

        delete curr;

        return head;
    }
};