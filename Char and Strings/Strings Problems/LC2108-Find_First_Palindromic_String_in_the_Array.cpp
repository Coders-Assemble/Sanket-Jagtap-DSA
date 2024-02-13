#include <iostream>
#include <vector>
using namespace std;

// TC => O(m*n)
// SC => O(1)

class Solution
{
public:
    bool isPalindrome(string str)
    {
        int low = 0;
        int high = str.size() - 1;
        while (low < high)
        {
            if (str[low] != str[high])
            {
                return false;
            }
            low++, high--;
        }
        return true;
    }

    string firstPalindrome(vector<string> &words)
    {
        for (auto str : words)
        {
            if (isPalindrome(str))
            {
                return str;
            }
        }
        return "";
    }
};