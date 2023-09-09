#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &arr, int divisor, int threshold)
    {
        int result = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            result += arr[i] / divisor;
            if (arr[i] % divisor)
                result++;
        }

        if (result <= threshold)
            return true;
        else
            return false;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int max_ele = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            max_ele = max(max_ele, nums[i]);
        }

        int s = 1;
        int e = max_ele;
        int ans = 0;

        while (s <= e)
        {
            int mid = (s + e) / 2;

            if (isPossible(nums, mid, threshold))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int sumOfResult(vector<int> &arr, int divisor)
    {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += ceil((double)arr[i] / (double)divisor);
        }
        return sum;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (sumOfResult(nums, mid) <= threshold)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};