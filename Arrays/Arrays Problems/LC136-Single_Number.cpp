#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Brute force - TLE
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                    count++;
            }
            if (count == 1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

// Better approach
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }

        for (auto it : mpp)
        {
            if (it.second == 1)
            {
                return it.first;
            }
        }
        return -1;
    }
};

// Optimal approach
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};