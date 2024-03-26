#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0 && nums[i] <= n)
            {
                arr[nums[i]] = 1;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (arr[i] == 0)
            {
                return i;
            }
        }

        return n + 1;
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        bool containsOne = false;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                containsOne = true;

            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }

        if (containsOne == false)
            return 1;

        for (int i = 0; i < n; i++)
        {
            int num = abs(nums[i]);
            int idx = num - 1;

            if (nums[idx] < 0)
                continue;

            nums[idx] *= -1;
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};