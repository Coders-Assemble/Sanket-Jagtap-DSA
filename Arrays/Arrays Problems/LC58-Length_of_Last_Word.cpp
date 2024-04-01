#include <iostream>
using namespace std;

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i = s.size() - 1;
        int length = 0;

        while (s[i] == ' ')
        {
            i--;
        }

        while (i >= 0 && s[i] != ' ')
        {
            length++;
            i--;
        }

        return length;
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int idx = s.find_last_not_of(' ') + 1;

        s.erase(idx);

        int last_space_idx = s.find_last_of(' ');

        return last_space_idx == string::npos ? s.size() : s.size() - last_space_idx - 1;
    }
};