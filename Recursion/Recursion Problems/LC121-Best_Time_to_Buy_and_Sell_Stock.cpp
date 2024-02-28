#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n) Auxillary stack space

class Solution
{
public:
    void maxProfitFinder(vector<int> &prices, int ind, int &minPrice, int &maxProfit)
    {
        if (ind == prices.size())
            return;

        if (prices[ind] < minPrice)
            minPrice = prices[ind];
        int profit = prices[ind] - minPrice;
        maxProfit = max(maxProfit, profit);

        maxProfitFinder(prices, ind + 1, minPrice, maxProfit);
    }

    int maxProfit(vector<int> &prices)
    {
        int minPrice = prices[0];
        int maxProfit = 0;

        maxProfitFinder(prices, 1, minPrice, maxProfit);
        return maxProfit;
    }
};