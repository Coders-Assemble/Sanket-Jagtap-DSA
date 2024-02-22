#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxArea = 0;

        while (left < right)
        {
            int length = min(height[left], height[right]);
            int width = right - left;
            int area = length * width;
            maxArea = max(area, maxArea);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
    }
};