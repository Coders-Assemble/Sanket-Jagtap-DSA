#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    int checkRedundancy(string s)
    {
        stack<char> st;
        for (auto ch : s)
        {
            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                if (st.top() == '(')
                {
                    return 1;
                }
                else
                {
                    while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                    {
                        st.pop();
                    }
                    if (st.top() == '(')
                    {
                        st.pop();
                    }
                }
            }
        }
        return 0;
    }
};
