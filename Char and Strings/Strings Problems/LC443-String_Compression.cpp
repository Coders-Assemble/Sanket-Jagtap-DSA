#include <iostream>
#include <vector>
using namespace std;

// Time Complexity (TC): O(n)
// Space Complexity (SC): O(1)

class Solution
{
public:
    int compress(vector<char> &s)
    {
        int index = 0;
        int count = 1;
        char prev = s[0];

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == prev)
            {
                count++;
            }
            else
            {
                s[index] = prev;
                index++;
                if (count > 1)
                {
                    int start = index;
                    while (count)
                    {
                        s[index] = (count % 10) + '0';
                        count = count / 10;
                        index++;
                    }
                    reverse(s.begin() + start, s.begin() + index);
                }
                prev = s[i];
                count = 1;
            }
        }

        s[index] = prev;
        index++;
        if (count > 1)
        {
            int start = index;
            while (count)
            {
                s[index] = (count % 10) + '0';
                count = count / 10;
                index++;
            }
            reverse(s.begin() + start, s.begin() + index);
        }

        return index;
    }
};