#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> result(n);

        left[0] = 1;
        for (int i = 1; i < n; i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }

        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            result[i] = left[i] * right[i];
        }

        return result;
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);

        result[0] = 1;
        for (int i = 1; i < n; i++)
        {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            int x = result[i];
            result[i] = rightProduct * x;
            rightProduct *= nums[i];
        }

        return result;
    }
};