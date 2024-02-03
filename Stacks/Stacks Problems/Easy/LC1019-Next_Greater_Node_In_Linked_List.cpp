#include <iostream>
#include <vector>
#include <stack>
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
    ListNode *reverseList(ListNode *&head)
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

    vector<int> nextLargerNodes(ListNode *head)
    {
        head = reverseList(head);

        stack<int> st;
        vector<int> v;

        while (head != NULL)
        {
            while (!st.empty() && st.top() <= head->val)
            {
                st.pop();
            }

            if (st.empty())
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(st.top());
            }

            st.push(head->val);
            head = head->next;
        }

        reverse(v.begin(), v.end());

        return v;
    }
};

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> ll;
        while (head)
        {
            ll.push_back(head->val);
            head = head->next;
        }

        stack<int> st;
        vector<int> ans(ll.size());

        for (int i = 0; i < ll.size(); i++)
        {
            while (!st.empty() && ll[i] > ll[st.top()])
            {
                int kids = st.top();
                st.pop();
                ans[kids] = ll[i];
            }
            st.push(i);
        }

        return ans;
    }
};

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> ll;
        while (head)
        {
            ll.push_back(head->val);
            head = head->next;
        }

        stack<int> st;

        for (int i = 0; i < ll.size(); i++)
        {
            while (!st.empty() && ll[i] > ll[st.top()])
            {
                int kids = st.top();
                st.pop();
                ll[kids] = ll[i];
            }
            st.push(i);
        }

        while (!st.empty())
        {
            ll[st.top()] = 0;
            st.pop();
        }

        return ll;
    }
};