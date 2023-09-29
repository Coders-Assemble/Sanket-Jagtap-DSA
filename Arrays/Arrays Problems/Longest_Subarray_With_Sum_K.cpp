#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Brute Force
// TC => O(n^2)
// SC => O(1)

int longestSubarrayWithSumK(vector<int> arr, long long k)
{
    int maxLen = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (sum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}

