#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    vector<int> twoSum(vector<int> &arr, int target)
    {
        int low = 0;
        int high = arr.size() - 1;

        while (low < high)
        {
            if (arr[low] + arr[high] == target)
            {
                return {low + 1, high + 1};
            }
            else if (arr[low] + arr[high] > target)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
        return {0, 0};
    }
};