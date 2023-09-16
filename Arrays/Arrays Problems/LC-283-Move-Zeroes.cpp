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

// Two Pointers Approach
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        if (nums.size() == 1)
            return;
        int j = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                j = i;
                break;
            }
        }

        if (j == -1)
            return;

        for (int i = j + 1; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};