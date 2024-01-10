#include <iostream>
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