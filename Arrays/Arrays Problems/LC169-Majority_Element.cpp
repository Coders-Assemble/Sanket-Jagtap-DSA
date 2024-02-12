#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Brute force - (TLE)
// TC => O(n^2)
// SC => O(1)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            int num = nums[i];
            for (int j = 0; j < n; j++)
            {
                if (num == nums[j])
                {
                    cnt++;
                }
                if (cnt > n / 2)
                {
                    return num;
                }
            }
        }
        return -1;
    }
};

// Better approach - using map
// TC => O(nlogn) + O(n)
// SC => O(n)
int majorityElement(vector<int> nums)
{
    int n = nums.size();

    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        mpp[num]++;
    }

    for (auto it : mpp)
    {
        if (it.second > n / 2)
        {
            return it.first;
        }
    }
    return -1;
}

// Optimal Approach - Moore's Voting Algorithm
// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        int el;

        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                cnt = 1;
                el = nums[i];
            }
            else if (nums[i] == el)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return el;
    }
};