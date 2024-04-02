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

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.size();
        vector<int> m1(256, 0), m2(256, 0);

        for (int i = 0; i < n; i++)
        {
            if (m1[s[i]] != m2[t[i]])
            {
                return false;
            }

            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
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
        unordered_map<char, char> mpp1;
        unordered_map<char, char> mpp2;

        int m = s.size();

        for (int i = 0; i < m; i++)
        {
            char ch1 = s[i];
            char ch2 = t[i];

            if (mpp1.find(ch1) != mpp1.end() && mpp1[ch1] != ch2 ||
                mpp2.find(ch2) != mpp2.end() && mpp2[ch2] != ch1)
            {
                return false;
            }

            mpp1[ch1] = ch2;
            mpp2[ch2] = ch1;
        }
        return true;
    }
};