#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> svec(26, 0);
        vector<int> tvec(26, 0);
        int ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            svec[s[i] - 'a']++;
            tvec[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            ans += abs(svec[i] - tvec[i]);
        }

        return ans / 2;
    }
};