#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// TC => O(n)
// SC => O(k)

class Solution
{
public:
    queue<int> modifyQueue(queue<int> q, int k)
    {
        stack<int> st;

        for (int i = 0; i < k; i++)
        {
            int element = q.front();
            q.pop();
            st.push(element);
        }

        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }

        int n = q.size() - k;
        while (n--)
        {
            int element = q.front();
            q.pop();
            q.push(element);
        }
        return q;
    }
};
