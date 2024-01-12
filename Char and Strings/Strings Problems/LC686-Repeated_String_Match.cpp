#include <iostream>
#include <vector>
using namespace std;

// TC => O((M+N) * (N+M))
// SC => O(N+M)

class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        int cnt = 0;
        string s = "";

        while (s.size() < b.size())
        {
            s += a;
            cnt++;
        }

        if (s.find(b) != string::npos)
        {
            return cnt;
        }

        s += a;
        cnt++;

        if (s.find(b) != string::npos)
        {
            return cnt;
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

    int KMP_MATCH(string haystack, string needle)
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
            return 1;
        }
        return 0;
    }

    int repeatedStringMatch(string a, string b)
    {
        if (a == b)
            return 1;

        int repeat = 1;
        string temp = a;

        while (temp.size() < b.size())
        {
            temp += a;
            repeat++;
        }

        if (KMP_MATCH(temp, b) == 1)
        {
            return repeat;
        }

        if (KMP_MATCH(temp + a, b) == 1)
        {
            return repeat + 1;
        }

        return -1;
    }
};