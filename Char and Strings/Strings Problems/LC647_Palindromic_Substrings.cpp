#include <iostream>
#include <string>
using namespace std;

// TC => O(N^2)
// SC => O(1)

class Solution
{
public:
    int expandAroundIndex(string s, int left, int right)
    {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s)
    {
        int totalCount = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            int oddKaAns = expandAroundIndex(s, i, i);
            totalCount = totalCount + oddKaAns;

            int evenKaAns = expandAroundIndex(s, i, i + 1);
            totalCount = totalCount + evenKaAns;
        }
        return totalCount;
    }
};