#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Using HashMap
// TC => O(n)
// SC => O(n)

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (mpp[nums[i]] > 1)
            {
                return true;
            }
        }
        return false;
    }
};

// Using set
// TC => O(n)
// SC => O(n)

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(nums[i]) != s.end())
            {
                return true;
            }
            s.insert(nums[i]);
        }

        return false;
    }
};