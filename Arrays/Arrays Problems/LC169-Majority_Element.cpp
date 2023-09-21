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
