#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Left -> Right
// TC => O(n)
// SC => O(n)

class Solution
{
public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n)
    {
        vector<long long> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

// Right -> Left
// TC => O(n)
// SC => O(n)

class Solution
{
public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n)
    {
        vector<long long> ans(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                ans[i] = arr[st.top()];
            }

            st.push(i);
        }

        return ans;
    }
};