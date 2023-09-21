#include <iostream>
#include <vector>
using namespace std;

// Brute force - using merge sort
// TC => O(nlogn)
// SC => O(n)

// Better approach - Counting values
// TC = O(2n)
// SC = O(1)

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int count0 = 0, count1 = 0, count2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                count0++;
            else if (nums[i] == 1)
                count1++;
            else
                count2++;
        }

        int x = 0;
        while (count0--)
        {
            nums[x] = 0;
            x++;
        }
        while (count1--)
        {
            nums[x] = 1;
            x++;
        }
        while (count2--)
        {
            nums[x] = 2;
            x++;
        }
    }
};

// Optimal approach - Dutch National Flag Algorithm (DNF)
// TC => O(n)
// SC => O(1)

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
