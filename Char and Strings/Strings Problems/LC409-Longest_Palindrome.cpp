#include <iostream>
#include <vector>
#include <map>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 1)
            return 1;

        int ans = 0;
        map<char, int> mpp;

        for (int i = 0; i < n; i++)
        {
            mpp[s[i]]++;
        }

        bool hasOddFrequency = false;

        for (auto it : mpp)
        {
            if (it.second % 2 == 1)
            {
                hasOddFrequency = true;
                ans += it.second - 1;
            }
            else
            {
                ans += it.second;
            }
        }

        if (hasOddFrequency)
        {
            ans++;
        }

        return ans;
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 1)
            return 1;

        int ans = 0;
        vector<int> lower(26, 0), upper(26, 0);

        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'a')
            {
                lower[s[i] - 'a']++;
            }
            else
            {
                upper[s[i] - 'A']++;
            }
        }

        bool hasOddFrequency = false;

        for (int i = 0; i < 26; i++)
        {
            if (lower[i] % 2 == 1)
            {
                hasOddFrequency = true;
                ans += lower[i] - 1;
            }
            else
            {
                ans += lower[i];
            }

            if (upper[i] % 2 == 1)
            {
                hasOddFrequency = true;
                ans += upper[i] - 1;
            }
            else
            {
                ans += upper[i];
            }
        }

        if (hasOddFrequency)
        {
            ans++;
        }

        return ans;
    }
};