#include <iostream>
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