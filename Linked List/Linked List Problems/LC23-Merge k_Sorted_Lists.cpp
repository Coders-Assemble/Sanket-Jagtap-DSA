#include <iostream>
#include <vector>
using namespace std;

// TC => O(k^2 * n)
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
    ListNode *merge(ListNode *&list1, ListNode *&list2)
    {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if (list1)
            temp->next = list1;
        else
            temp->next = list2;

        return dummyNode->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;

        ListNode *head = lists[0];

        for (int i = 1; i < lists.size(); i++)
        {
            head = merge(head, lists[i]);
        }

        return head;
    }
};