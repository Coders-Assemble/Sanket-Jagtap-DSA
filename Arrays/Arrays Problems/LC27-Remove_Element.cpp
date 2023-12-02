#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j)
        {
            if (nums[i] == val)
            {
                swap(nums[i], nums[j]);
                j--;
            }
            else
            {
                i++;
            }
        }

        return i;
    }
};

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int index = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }
};