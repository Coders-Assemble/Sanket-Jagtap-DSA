#include <iostream>
#include <vector>
using namespace std;

// Brute force
// TC => O(n^2)
// SC => O(1)

int bestTimeToBuyAndSellStock(vector<int> &prices)
{
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[j] > prices[i])
            {
                int profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }
    }
    return maxProfit;
}

// Optimal approach
// TC => O(n)
// SC => O(1)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            int profit = prices[i] - mini;

            maxProfit = max(maxProfit, profit);

            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};