#include <iostream>
#include <vector>
#include <string>
using namespace std;

// (TC) => O(S), where S is the sum of the lengths of all the input strings.
// (SC) => O(1)

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
            return strs[0];

        string ans;
        int i = 0;
        while (true)
        {
            char curr_ch = 0;
            for (auto str : strs)
            {
                if (i >= str.length())
                {
                    // out of bound
                    curr_ch = 0;
                    break;
                }

                if (curr_ch == 0)
                {
                    // just started
                    curr_ch = str[i];
                }
                else if (str[i] != curr_ch)
                {
                    curr_ch = 0;
                    break;
                }
            }

            if (curr_ch == 0)
            {
                break;
            }

            ans.push_back(curr_ch);
            i++;
        }
        return ans;
    }
};