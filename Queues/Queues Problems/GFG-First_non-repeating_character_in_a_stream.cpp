#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    string FirstNonRepeating(string s)
    {
        vector<int> hash(26, 0);
        queue<char> q;
        string ans;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            hash[ch - 'a']++;
            q.push(ch);

            while (!q.empty())
            {
                if (hash[q.front() - 'a'] > 1)
                {
                    q.pop();
                }
                else
                {
                    ans.push_back(q.front());
                    break;
                }
            }

            if (q.empty())
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};
