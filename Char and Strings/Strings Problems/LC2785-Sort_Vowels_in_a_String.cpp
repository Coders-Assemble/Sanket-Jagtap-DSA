#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC => O(nlogn)
// SC => O(n)

class Solution
{
public:
    string sortVowels(string s)
    {
        int n = s.size();
        vector<int> vovels;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                vovels.push_back(s[i]);
                s[i] = '#';
            }
            else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                vovels.push_back(s[i]);
                s[i] = '#';
            }
        }

        sort(vovels.begin(), vovels.end());

        int i = 0, j = 0;

        while (j < vovels.size())
        {
            if (s[i] == '#')
            {
                s[i] = vovels[j];
                j++;
            }
            i++;
        }

        return s;
    }
};

// TC => O(n)
// Sc => O(n)

class Solution
{
public:
    string sortVowels(string s)
    {
        int n = s.size();
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                lower[s[i] - 'a']++;
                s[i] = '#';
            }
            else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                upper[s[i] - 'A']++;
                s[i] = '#';
            }
        }

        string str = "";

        for (int i = 0; i < 26; i++)
        {
            char c = 'A' + i;
            while (upper[i])
            {
                str += c;
                upper[i]--;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            char c = 'a' + i;
            while (lower[i])
            {
                str += c;
                lower[i]--;
            }
        }

        int i = 0, j = 0;

        while (j < str.size())
        {
            if (s[i] == '#')
            {
                s[i] = str[j];
                j++;
            }
            i++;
        }

        return s;
    }
};