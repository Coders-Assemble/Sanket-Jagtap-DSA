#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute Force
// TC => O(N^2)
// SC => O(1)

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            int sub_sum = 0;
            for (int j = i; j < n; j++)
            {
                sub_sum = sub_sum + nums[j];
                if (sub_sum == k)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// Optimal Approach
// TC => O(N) or O(NlogN)
// Here we are using unorderd map in which for best and avg case map opertions takes O(1) and worst case takes O(N).
// If we use Map, map operations takes O(logN).
// SC => O(N) as we are using a map data structure.

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int count = 0;
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            int remove = sum - k;
            count += mpp[remove];
            mpp[sum]++;
        }
        return count;
    }
};
