#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);

        left[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], height[i]);
        }

        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += min(left[i], right[i]) - height[i];
        }

        return ans;
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int leftMax = height[0], rightMax = height[n - 1];
        int maxHeight = height[0], index = 0, water = 0;

        // Max height
        for (int i = 0; i < n; i++)
        {
            if (height[i] > maxHeight)
            {
                maxHeight = height[i];
                index = i;
            }
        }

        // Left part
        for (int i = 0; i < index; i++)
        {
            if (leftMax > height[i])
            {
                water += leftMax - height[i];
            }
            else
            {
                leftMax = height[i];
            }
        }

        // Right part
        for (int i = n - 1; i > index; i--)
        {
            if (rightMax > height[i])
            {
                water += rightMax - height[i];
            }
            else
            {
                rightMax = height[i];
            }
        }

        return water;
    }
};