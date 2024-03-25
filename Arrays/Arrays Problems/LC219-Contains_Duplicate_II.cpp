#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (mpp.find(nums[i]) != mpp.end() && abs(mpp[nums[i]] - i) <= k)
            {
                return true;
            }
            else
            {
                mpp[nums[i]] = i;
            }
        }

        return false;
    }
};

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_set<int> st;

        int i = 0, j = 0;

        while (j < n)
        {
            if (abs(i - j) > k)
            {
                st.erase(nums[i]);
                i++;
            }

            if (st.find(nums[j]) != st.end())
            {
                return true;
            }

            st.insert(nums[j]);
            j++;
        }

        return false;
    }
};