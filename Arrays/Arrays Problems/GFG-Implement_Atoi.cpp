#include <iostream>
using namespace std;

class Solution
{
public:
    int atoi(string s)
    {
        int i = 0;
        int integer = 0;
        int sign = 1;

        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }

        while (i < s.size())
        {
            if (isdigit(s[i]))
            {
                integer = integer * 10 + (s[i] - '0');
                i++;
            }
            else
            {
                return -1;
            }
        }

        return integer * sign;
    }
};
