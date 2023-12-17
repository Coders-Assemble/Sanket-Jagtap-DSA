#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

// TC => O(n*m) where 'n' is the number of strings in the vector and 'm' is the length of the common prefix
// SC => O(1)

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j])
            {
                j++;
            }

            prefix = prefix.substr(0, j);

            if (prefix.empty())
            {
                return "";
            }
        }
        return prefix;
    }
};

// TC => O(n * log(n) + m)
// SC => O(1)

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();

        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[n - 1];

        int i = 0;
        while (i < a.size())
        {
            if (a[i] == b[i])
            {
                i++;
            }
            else
            {
                break;
            }
        }
        return a.substr(0, i);
    }
};