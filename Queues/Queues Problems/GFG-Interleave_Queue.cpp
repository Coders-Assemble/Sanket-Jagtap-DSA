#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TC => O(n)
// SC => O(n)

class Solution
{
public:
    vector<int> rearrangeQueue(queue<int> &q)
    {
        int n = q.size();
        vector<int> v;
        queue<int> q2;

        int k = n / 2;

        for (int i = 0; i < k; i++)
        {
            int element = q.front();
            q.pop();
            q2.push(element);
        }

        while (!q.empty() && !q2.empty())
        {
            int first = q2.front();
            q2.pop();
            v.push_back(first);

            int second = q.front();
            q.pop();
            v.push_back(second);
        }
        return v;
    }
};
