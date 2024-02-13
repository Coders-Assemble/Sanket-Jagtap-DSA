#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// TC => O(n)
// SC => O(k)

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    vector<long long> ans;
    deque<int> dq;

    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    for (int i = K; i < N; i++)
    {
        if (dq.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(A[dq.front()]);
        }

        while ((!dq.empty()) && (i - dq.front() >= K))
        {
            dq.pop_front();
        }

        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    if (dq.empty())
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(A[dq.front()]);
    }

    return ans;
}