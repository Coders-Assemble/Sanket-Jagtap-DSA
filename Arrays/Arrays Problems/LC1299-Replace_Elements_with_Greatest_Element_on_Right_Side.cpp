#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans;
        int maxElement = INT_MIN;

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(maxElement);
            }

            if (arr[i] > maxElement)
            {
                maxElement = arr[i];
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        int maxElement = INT_MIN;

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = maxElement;
            }

            if (arr[i] > maxElement)
            {
                maxElement = arr[i];
            }
        }
        return ans;
    }
};