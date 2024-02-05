#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n = s.size();
        vector<int> hash(26);

        for (int i = 0; i < n; i++)
        {
            hash[s[i] - 'a']++;
        }

        for (int i = 0; i < n; i++)
        {
            if (hash[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};