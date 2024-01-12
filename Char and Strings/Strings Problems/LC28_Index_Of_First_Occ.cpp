#include <iostream>
#include <vector>
#include <string>
using namespace std;

// TC => O((n - m + 1) * m)
// SC => O(1)

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++)
        {
            if (haystack.substr(i, m) == needle)
            {
                return i;
            }
        }
        return -1;
    }
};

// TC => O((n - m + 1) * m
// SC => O(1)

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (needle[j] != haystack[i + j])
                {
                    break;
                }

                if (j == m - 1)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};

class Solution
{
public:
    void lpsFind(vector<int> &lps, string needle)
    {
        int prefix = 0;
        int suffix = 1;

        while (suffix < needle.size())
        {
            // Matched
            if (needle[prefix] == needle[suffix])
            {
                lps[suffix] = prefix + 1;
                prefix++, suffix++;
            }
            // Unmathed
            else
            {
                if (prefix == 0)
                {
                    lps[suffix] = 0;
                    suffix++;
                }
                else
                {
                    prefix = lps[prefix - 1];
                }
            }
        }
    }

    int strStr(string haystack, string needle)
    {
        vector<int> lps(needle.size(), 0);
        lpsFind(lps, needle);
        int first = 0, second = 0;

        while (first < haystack.size() && second < needle.size())
        {
            // Matched
            if (haystack[first] == needle[second])
            {
                first++, second++;
            }
            // Unmatched
            else
            {
                if (second == 0)
                {
                    first++;
                }
                else
                {
                    second = lps[second - 1];
                }
            }
        }

        if (second == needle.size())
        {
            return first - second;
        }
        return -1;
    }
};