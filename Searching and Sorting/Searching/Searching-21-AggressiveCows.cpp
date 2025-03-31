#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canWePlace(vector<int> &stalls, int minDist, int k) {
        int cowsCount = 1;
        int lastCowPlaced = stalls[0];

        for (int i = 0; i < stalls.size(); i++) {
            if (stalls[i] - lastCowPlaced >= minDist) {
                cowsCount++;
                lastCowPlaced = stalls[i];
            }
            if (cowsCount >= k)
                return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int s = 1, e = stalls[n - 1] - stalls[0];

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (canWePlace(stalls, mid, k))
                s = mid + 1;
            else
                e = mid - 1;
        }
        return e;
    }
};