#include <iostream>
#include <vector>
using namespace std;

// Brute force approach
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int> temp1;
        vector<int> temp2;

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                temp2.push_back(nums[i]);
            }
            else
            {
                temp1.push_back(nums[i]);
            }
        }

        int index = 0;
        for (auto it : temp1)
        {
            nums[index] = it;
            index++;
        }

        for (auto it : temp2)
        {
            nums[index] = it;
            index++;
        }
    }
};
