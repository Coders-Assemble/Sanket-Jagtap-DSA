#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int hash[256] = {0};
        bool istCharMapped[256] = {0};

        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i]] == 0 && istCharMapped[t[i]] == 0)
            {
                hash[s[i]] = t[i];
                istCharMapped[t[i]] = true;
            }
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i]] != t[i])
            {
                return false;
            }
        }
        return true;
    }
};

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, vector<int>> m1;
        unordered_map<char, vector<int>> m2;

        for (int i = 0; i < s.size(); i++)
        {
            m1[s[i]].push_back(i);
            m2[t[i]].push_back(i);

            if (m1[s[i]] != m2[t[i]])
            {
                return false;
            }
        }
        return true;
    }
};