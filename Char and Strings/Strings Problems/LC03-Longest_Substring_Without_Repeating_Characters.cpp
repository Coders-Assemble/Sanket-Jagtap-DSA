#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<bool> hash(256, 0);
        int i = 0, j = 0, maxLen = 0;

        while (j < s.size())
        {
            while (hash[s[j]])
            {
                hash[s[i]] = 0;
                i++;
            }
            hash[s[j]] = 1;
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};