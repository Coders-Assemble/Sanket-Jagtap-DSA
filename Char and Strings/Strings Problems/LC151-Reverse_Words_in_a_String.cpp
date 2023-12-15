#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    string reverseWords(string s)
    {
        int i = s.size() - 1;
        string ans = "";

        while (i >= 0)
        {
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;

            string temp = "";
            while (i >= 0 && s[i] != ' ')
            {
                temp += s[i];
                i--;
            }

            reverse(temp.begin(), temp.end());

            if (ans.empty())
            {
                ans = temp;
            }
            else
            {
                ans = ans + ' ' + temp;
            }
        }
        return ans;
    }
};