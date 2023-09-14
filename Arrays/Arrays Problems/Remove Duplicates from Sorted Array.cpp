#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Brute force approach
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> st;
        for (int i = 0; i < nums.size(); i++)
            st.insert(nums[i]);

        int index = 0;
        for (auto it : st)
        {
            nums[index] = it;
            index++;
        }
        return index;
    }
};

// Two pointers approach
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                nums[i + 1] = nums[j];
                i++;
            }
        }
        return i + 1;
    }
};