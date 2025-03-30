#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &arr, int n, int k, int maxAllowedTime) {
        int painters = 1, time = 0;

        for (int i = 0; i < n; i++) {
            if (time + arr[i] <= maxAllowedTime)
                time += arr[i];
            else {
                painters++;
                time = arr[i];
            }
        }
        return painters <= k;
    }

    int minTime(vector<int> &arr, int k) {
        int n = arr.size();
        int s = *max_element(arr.begin(), arr.end());
        int e = accumulate(arr.begin(), arr.end(), 0);

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (isPossible(arr, n, k, mid))
                e = mid - 1;
            else
                s = mid + 1;
        }
        return s;
    }
};
