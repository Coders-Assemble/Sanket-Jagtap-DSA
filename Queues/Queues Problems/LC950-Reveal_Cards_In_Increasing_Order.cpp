#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// TC => O(nlogn)
// SC => O(1)

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        vector<int> ans(n, 0);

        int i = 0;
        int j = 0;
        bool skip = false;

        sort(deck.begin(), deck.end());

        while (i < n)
        {
            if (ans[j] == 0)
            {
                if (skip == false)
                {
                    ans[j] = deck[i];
                    ;
                    i++;
                }

                skip = !skip;
            }

            j = (j + 1) % n;
        }
        return ans;
    }
};

// TC => O(nlogn)
// SC => O(n)

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        vector<int> ans(n);
        queue<int> que;

        for (int i = 0; i < n; i++)
        {
            que.push(i);
        }

        sort(deck.begin(), deck.end());

        for (int i = 0; i < n; i++)
        {
            int idx = que.front();
            que.pop();

            ans[idx] = deck[i];

            if (!que.empty())
            {
                que.push(que.front());
                que.pop();
            }
        }

        return ans;
    }
};