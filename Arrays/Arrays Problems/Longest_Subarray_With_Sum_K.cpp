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

// Better Approach - Using Map
// TC => O(nlogn)
// SC => O(n)

int getLongestSubarray(vector<int> &a, int k)
{
    map<long long, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];

        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}
