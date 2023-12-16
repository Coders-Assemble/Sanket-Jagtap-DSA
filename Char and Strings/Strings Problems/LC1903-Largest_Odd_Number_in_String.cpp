#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    string largestOddNumber(string num)
    {
        string str = "";
        for (int i = num.size() - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 != 0)
            {
                while (i >= 0)
                {
                    str += num[i];
                    i--;
                }
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    string largestOddNumber(string num)
    {
        string str = "";
        int j = 0;
        for (int i = num.size() - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 != 0)
            {
                while (j <= i)
                {
                    str += num[j];
                    j++;
                }
            }
        }
        return str;
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    string largestOddNumber(string num)
    {
        if (num.back() % 2 == 1)
            return num;

        int i = num.size() - 1;
        while (i >= 0)
        {
            if (num[i] % 2 == 1)
                return num.substr(0, i + 1);
            i--;
        }
        return "";
    }
};