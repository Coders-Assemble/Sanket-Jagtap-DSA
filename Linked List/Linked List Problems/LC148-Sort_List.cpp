#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC => O(n + nlogn + n)
// SC => O(n)

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
    ListNode *sortList(ListNode *head)
    {
        vector<int> v;
        ListNode *temp = head;

        while (temp != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }

        sort(v.begin(), v.end());

        int i = 0;
        temp = head;

        while (temp != NULL)
        {
            temp->val = v[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
};

// TC => O(nlogn)
// SC => O(1) + Auxiliary stack space

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
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;

        while (head1 != NULL && head2 != NULL)
        {
            if (head1->val <= head2->val)
            {
                temp->next = head1;
                temp = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                temp = head2;
                head2 = head2->next;
            }
        }

        if (head1)
            temp->next = head1;
        else
            temp->next = head2;

        return dummyNode->next;
    }

    ListNode *mergeSort(ListNode *head)
    {
        // Base case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Mid of Linked List
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Mark the head of left LL and right LL and point left LL to null
        ListNode *leftHead = head;
        ListNode *rightHead = slow->next;
        slow->next = NULL;

        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);
        return merge(leftHead, rightHead);
    }

    ListNode *sortList(ListNode *head)
    {
        head = mergeSort(head);
        return head;
    }
};