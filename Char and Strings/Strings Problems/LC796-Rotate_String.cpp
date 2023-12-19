#include <iostream>
#include <vector>
using namespace std;

// TC => O(n^2)
// SC => O(n)

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;

        string str = s + s;
        int n = str.size() - goal.size();
        for (int i = 0; i < n; i++)
        {
            if (str.substr(i, goal.size()) == goal)
            {
                return true;
            }
        }
        return false;
    }
};

// TC => O(n^2)
// SC => O(n)

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;

        if (s == goal)
            return true;

        int goalLen = goal.size();

        while (goalLen--)
        {
            if (s == goal)
                return true;

            s = s.substr(1) + s[0];
        }
        return false;
    }
};

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    bool rotateString(string s, string goal)
    {

        if (s.size() != goal.size())
        {
            return false;
        }

        return (s + s).find(goal) != string::npos;
    }
};