#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC => O(nlogn)
// SC => O(1)

class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        return ((nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]));
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int n = nums.size();

        long long largest = INT_MIN;
        long long secondLargest = INT_MIN;
        long long smallest = INT_MAX;
        long long secondSmallest = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > largest)
            {
                secondLargest = largest;
                largest = nums[i];
            }
            else if (nums[i] > secondLargest)
            {
                secondLargest = nums[i];
            }

            if (nums[i] < smallest)
            {
                secondSmallest = smallest;
                smallest = nums[i];
            }
            else if (nums[i] < secondSmallest)
            {
                secondSmallest = nums[i];
            }
        }

        cout << largest << " " << secondLargest << " " << smallest << " " << secondSmallest << endl;

        return ((largest * secondLargest) - (smallest * secondSmallest));
    }
};
