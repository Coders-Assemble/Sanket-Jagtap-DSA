#include <iostream>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size();
        string str;

        for (int i = 0; i < n; i++)
        {
            s[i] = tolower(s[i]);
        }

        for (auto ch : s)
        {
            if (iswalnum(ch))
            {
                str += ch;
            }
        }

        cout << str << endl;

        int i = 0, j = str.size() - 1;

        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.size() - 1;

        while (start <= end)
        {
            if (!isalnum(s[start]))
            {
                start++;
                continue;
            }

            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }

            if (tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};