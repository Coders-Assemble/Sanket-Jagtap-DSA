#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            st.push(i);
        }

        while (st.size() > 1)
        {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();

            if (M[first][second])
            {
                st.push(second);
            }
            else
            {
                st.push(first);
            }
        }

        if (st.empty())
        {
            return -1;
        }

        int num = st.top();
        st.pop();

        int row = 0, col = 0;

        for (int i = 0; i < n; i++)
        {
            row += M[num][i];
            col += M[i][num];
        }

        return (row == 0 && col == n - 1) ? num : -1;
    }
};