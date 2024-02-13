#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// TC => O(n)
// SC => O(k)

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k)
    {
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && arr[i] >= arr[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for (int i = k; i < arr.size(); i++)
        {
            ans.push_back(arr[dq.front()]);

            if (!dq.empty() && (i - dq.front() >= k))
            {
                dq.pop_front();
            }

            while (!dq.empty() && arr[i] >= arr[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }
        ans.push_back(arr[dq.front()]);
        return ans;
    }
};