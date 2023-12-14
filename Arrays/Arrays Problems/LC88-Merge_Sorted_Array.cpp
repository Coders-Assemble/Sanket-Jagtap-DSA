#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O((m + n) log(m + n)) // Due to sorting
// Space Complexity: O(1)

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int j = 0;
        for (int i = m; i < m + n; i++)
        {
            if (j < n)
            {
                nums1[i] = nums2[j];
                j++;
            }
        }
        sort(nums1.begin(), nums1.end());
    }
};

// Time Complexity (TC): O(m + n)
// Space Complexity (SC): O(m + n)

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> ans(m + n);

        int i = 0;
        int j = 0;
        int k = 0;

        while (j < m && k < n)
        {
            if (nums1[j] <= nums2[k])
            {
                ans[i] = nums1[j];
                i++, j++;
            }
            else
            {
                ans[i] = nums2[k];
                i++, k++;
            }
        }

        while (j < m)
        {
            ans[i] = nums1[j];
            i++, j++;
        }

        while (k < n)
        {
            ans[i] = nums2[k];
            i++, k++;
        }

        for (int i = 0; i < m + n; i++)
        {
            nums1[i] = ans[i];
        }
    }
};

// TC => O(m+n)
// SC => O(1)

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0)
        {
            if (i >= 0 && nums1[i] >= nums2[j])
            {
                nums1[k] = nums1[i];
                k--, i--;
            }
            else
            {
                nums1[k] = nums2[j];
                k--, j--;
            }
        }
    }
};