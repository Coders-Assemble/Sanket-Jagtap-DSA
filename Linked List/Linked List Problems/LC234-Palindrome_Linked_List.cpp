#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

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
    bool isPalindrome(ListNode *head)
    {
        vector<int> arr;

        ListNode *temp = head;
        while (temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0;
        int j = arr.size() - 1;

        while (i < j)
        {
            if (arr[i] != arr[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = curr->next;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        if (head->next == NULL)
            return true;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        ListNode *reverseListHead = reverse(slow->next);

        ListNode *temp1 = head;
        ListNode *temp2 = reverseListHead;

        while (temp2 != NULL)
        {
            if (temp1->val != temp2->val)
            {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};