#include <iostream>
#include <string>
using namespace std;

// Brute force approach
// TC => O(N^2)
// SC => O(1)

class Solution
{
public:
    string removeDuplicates(string s)
    {
        int i = 0;
        while (i < s.length())
        {
            if (s[i] == s[i + 1])
            {
                s.erase(i, 2);
                i = 0;
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};

// Optimal Approach - 01
// TC => O(N)
// SC => O(N)

class Solution
{
public:
    string removeDuplicates(string s)
    {
        string str = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (str.length() > 0)
            {
                if (str[str.length() - 1] == s[i])
                {
                    str.pop_back();
                }
                else
                {
                    str.push_back(s[i]);
                }
            }
            else
            {
                str.push_back(s[i]);
            }
        }
        return str;
    }
};