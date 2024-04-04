#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    int maxDepth(string s)
    {
        stack<char> st;

        int result = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                st.pop();
            }

            result = max(result, (int)st.size());
        }

        return result;
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int maxDepth(string s)
    {

        int result = 0;
        int openBrackets = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                openBrackets++;
            }
            else if (ch == ')')
            {
                openBrackets--;
            }

            result = max(result, openBrackets);
        }

        return result;
    }
};