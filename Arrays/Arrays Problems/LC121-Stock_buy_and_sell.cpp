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