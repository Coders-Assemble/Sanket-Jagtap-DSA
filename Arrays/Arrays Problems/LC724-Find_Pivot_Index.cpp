#include <iostream>
#include <vector>
using namespace std;

// TC => O(n^2)
// SC => O(1)

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int left = 0;
            int leftSum = 0;

            while (left < i)
            {
                leftSum += nums[left];
                left++;
            }

            int right = i + 1;
            int rightSum = 0;
            while (right < n)
            {
                rightSum += nums[right];
                right++;
            }

            if (leftSum == rightSum)
                return i;
        }
        return -1;
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();

        int leftSum = 0;
        int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += nums[i];
        }
        int rightSum = totalSum - nums[0];

        for (int i = 0; i < n; i++)
        {
            if (leftSum == rightSum)
            {
                cout << leftSum << " " << rightSum << endl;
                return i;
            }

            leftSum += nums[i];
            if (i < n - 1)
            {
                rightSum -= nums[i + 1];
            }
        }
        cout << leftSum << " " << rightSum << endl;
        return -1;
    }
};