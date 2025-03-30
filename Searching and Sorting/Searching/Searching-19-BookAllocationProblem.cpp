#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int noOfStudents(vector<int> &arr, int mid) {
        int student = 1;
        int pagesAllocated = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (pagesAllocated + arr[i] <= mid)
                pagesAllocated += arr[i];
            else {
                student++;
                pagesAllocated = 0;
                if (pagesAllocated + arr[i] <= mid)
                    pagesAllocated += arr[i];
            }
        }
        return student;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n)
            return -1;

        int s = *max_element(arr.begin(), arr.end());
        int e = accumulate(arr.begin(), arr.end(), 0);

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (noOfStudents(arr, mid) > k)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return s;
    }
};
