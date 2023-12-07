#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mpp;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
        }

        for (auto it : mpp)
        {
            if (it.second > n / 3)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();

        int cnt1 = 0;
        int elem1 = INT_MIN;
        int cnt2 = 0;
        int elem2 = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && nums[i] != elem2)
            {
                cnt1 = 1;
                elem1 = nums[i];
            }
            else if (cnt2 == 0 && nums[i] != elem1)
            {
                cnt2 = 1;
                elem2 = nums[i];
            }
            else if (nums[i] == elem1) cnt1++;
            else if (nums[i] == elem2) cnt2++;
            else cnt1--, cnt2--;
        }

        vector<int> ans;
        cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == elem1) cnt1++;
            if (nums[i] == elem2) cnt2++;
        }

        if (cnt1 > n / 3) ans.push_back(elem1);
        if (cnt2 > n / 3) ans.push_back(elem2);

        return ans;
    }
};
