#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Approach 01
class Solution {
public:
    int findDays(vector<int>& arr, int cap){
        int day = 1;
        int rem_cap = cap;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] <= rem_cap){
                rem_cap -= arr[i];
            }
            else{
                day++;
                rem_cap = cap;
                rem_cap -= arr[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int sum = 0;
        int max_ele = INT_MIN;
        for(int i=0; i<weights.size(); i++){
            sum += weights[i];
            max_ele = max(max_ele, weights[i]);
        }

        int low = max_ele;
        int high = sum;
        int ans = INT_MAX;

        while(low <= high){
            int mid = (low + high)/2;

            int d = findDays(weights, mid);

            if(d <= days){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};