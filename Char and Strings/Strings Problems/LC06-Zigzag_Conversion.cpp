#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        vector<string> v(numRows, "");
        int j = 0;
        int direction = -1;

        for (int i = 0; i < s.size(); i++)
        {
            if (j == 0 || j == numRows - 1)
                direction *= -1;

            v[j] += s[i];

            if (direction == 1)
            {
                j++;
            }
            else
            {
                j--;
            }
        }

        string ans;
        for (auto it : v)
        {
            ans += it;
        }

        return ans;
    }
};