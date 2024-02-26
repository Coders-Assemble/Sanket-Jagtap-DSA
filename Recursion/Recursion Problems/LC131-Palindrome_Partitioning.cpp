#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void partition_helper(int ind, string &s, vector<vector<string>> &ans, vector<string> &v)
    {
        if (ind == s.size())
        {
            ans.push_back(v);
            return;
        }

        for (int i = ind; i < s.size(); i++)
        {
            if (isPalindrome(s, ind, i))
            {
                v.push_back(s.substr(ind, i - ind + 1));
                partition_helper(i + 1, s, ans, v);
                v.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> v;
        partition_helper(0, s, ans, v);
        return ans;
    }
};