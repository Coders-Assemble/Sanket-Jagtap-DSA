#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int findMax(vector<int> &arr)
    {
        int n = arr.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            maxi = max(arr[i], maxi);
        }
        return maxi;
    }

    long long findReqHrs(vector<int> &arr, int rate)
    {
        int n = arr.size();
        long long reqHrs = 0;

        for (int i = 0; i < n; i++)
        {
            reqHrs += arr[i] / rate;
            if (arr[i] % rate)
            {
                reqHrs++;
            }
        }

        return reqHrs;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1;
        int high = findMax(piles);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            long long totalHrs = findReqHrs(piles, mid);

            if (totalHrs <= h)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

class Solution
{
public:
    int findMax(vector<int> &arr)
    {
        int n = arr.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            maxi = max(arr[i], maxi);
        }
        return maxi;
    }

    long long findReqHrs(vector<int> &arr, int rate)
    {
        int n = arr.size();
        long long reqHrs = 0;

        for (int i = 0; i < n; i++)
        {
            reqHrs += ceil((double)(arr[i]) / (double)(rate));
        }

        return reqHrs;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1;
        int high = findMax(piles);
        int ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            long long totalHrs = findReqHrs(piles, mid);

            if (totalHrs <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};