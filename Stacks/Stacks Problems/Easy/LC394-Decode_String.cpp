#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> st;

        for (auto ch : s)
        {
            if (ch == ']')
            {
                string strToRepeat = "";
                while (!st.empty() && st.top() != "[")
                {
                    strToRepeat = st.top() + strToRepeat;
                    st.pop();
                }
                st.pop();

                string numericTimes = "";
                while (!st.empty() && isdigit(st.top()[0]))
                {
                    numericTimes = st.top() + numericTimes;
                    st.pop();
                }

                int n = stoi(numericTimes);

                string currentDecode = "";
                while (n--)
                {
                    currentDecode += strToRepeat;
                }

                st.push(currentDecode);
            }
            else
            {
                string temp(1, ch);
                st.push(temp);
            }
        }
        string ans;
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};