#include <iostream>
#include <vector>
using namespace std;

// Brute force approach
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int N = nums.size();
        for (int i = 0; i <= N; i++)
        {

            int flag = 0;

            for (int j = 0; j < N; j++)
            {
                if (nums[j] == i)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
                return i;
        }

        return -1;
    }
};

// Optimal approach-1
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int totalSum = n * (n + 1) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
        }
        return totalSum - sum;
    }
};