#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Brute force
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return v;
    }
};

// Optimal approach
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            int moreNeeded = target - num;
            if (mpp.find(moreNeeded) != mpp.end())
            {
                return {mpp[moreNeeded], i};
            }
            mpp[num] = i;
        }
        return {-1, -1};
    }
};