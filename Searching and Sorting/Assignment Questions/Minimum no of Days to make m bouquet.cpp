#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &arr, int days, int m, int k)
    {
        int n = arr.size();
        int count = 0;
        int bouquets = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= days)
            {
                count++;
            }
            else
            {
                bouquets += count / k;
                count = 0;
            }
        }
        bouquets += count / k;
        return bouquets >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        // long long val = m * k;
        long long val = m * 1ll * k * 1ll;
        if (val > n)
            return -1;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }

        int s = mini;
        int e = maxi;
        int ans = 0;
        while (s <= e)
        {
            int mid = (s + e) / 2;

            if (isPossible(bloomDay, mid, m, k))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};