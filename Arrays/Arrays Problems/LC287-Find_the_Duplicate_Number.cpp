#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Limit Exceeded
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    return nums[i];
                }
            }
        }

        return -1;
    }
};

// Works but modifies the array
// TC => O(nlogn)
// SC => O(n)

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return nums[i];
            }
        }

        return -1;
    }
};

// Works but modifies the array
// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]);

            if (nums[index] < 0)
            {
                return index;
            }

            nums[index] *= -1;
        }
        return -1;
    }
};

// Works but modifies the array
// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        while (nums[0] != nums[nums[0]])
        {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};