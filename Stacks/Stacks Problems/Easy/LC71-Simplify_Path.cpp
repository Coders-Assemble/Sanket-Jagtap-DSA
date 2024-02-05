#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        int i = 0;
        while (i < path.size())
        {
            int start = i;
            int end = i + 1;
            while (end < path.size() && path[end] != '/')
            {
                end++;
            }

            i = end;

            string minPath = path.substr(start, end - start);
            if (minPath == "/" || minPath == "/.")
            {
                continue;
            }

            if (minPath != "/..")
            {
                st.push(minPath);
            }
            else if (!st.empty())
            {
                st.pop();
            }
        }
        string ans = st.empty() ? "/" : "";
        while (!st.empty())
        {
            ans = st.top() + ans;
            ;
            st.pop();
        }
        return ans;
    }
};