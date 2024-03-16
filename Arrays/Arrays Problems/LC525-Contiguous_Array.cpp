#include <iostream>
#include <vector>
#include <map>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        map<int, int> mpp;
        int maxLen = 0;
        int currSum = 0;

        mpp[0] = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                currSum += 1;
            }
            else
            {
                currSum -= 1;
            }

            if (mpp.find(currSum) != mpp.end())
            {
                int len = i - mpp[currSum];
                maxLen = max(maxLen, len);
            }
            else
            {
                mpp[currSum] = i;
            }
        }

        return maxLen;
    }
};