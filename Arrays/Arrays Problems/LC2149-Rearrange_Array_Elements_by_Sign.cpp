#include <iostream>
#include <vector>
using namespace std;

// Brute Force
// TC => O(2n)
// SC => O(n)

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> positive;
        vector<int> negative;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                positive.push_back(nums[i]);
            }
            else
            {
                negative.push_back(nums[i]);
            }
        }

        // for(auto it: positive){
        //     cout<<it<<" ";
        // }cout<<endl;

        // for(auto it: negative){
        //     cout<<it<<" ";
        // }

        int j = 0, k = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                nums[i] = positive[j];
                j++;
            }
            else
            {
                nums[i] = negative[k];
                k++;
            }
        }
        return nums;
    }
};