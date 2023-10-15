#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Brute force
// TC => O(NlogN)
// SC => O(1)

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // TC => O(NlogN)

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s == t)
            return true;
        else
            return false;
    }
};

// Optimal approach
// TC => O(N+M)
// SC => O(1)

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int freqTable[256] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            freqTable[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++)
        {
            freqTable[t[i]]--;
        }

        for (int i = 0; i < 256; i++)
        {
            if (freqTable[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
