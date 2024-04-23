#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void findCombinations(int start, int &n, int k, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (k == 0)
        {
            ans.push_back(temp);
            return;
        }

        if (start > n)
            return;

        temp.push_back(start);
        findCombinations(start + 1, n, k - 1, temp, ans);
        temp.pop_back();
        findCombinations(start + 1, n, k, temp, ans);
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int start = 1;

        findCombinations(start, n, k, temp, ans);

        return ans;
    }
};

class Solution
{
public:
    void findCombinations(int start, int &n, int k, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (k == 0)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            temp.push_back(i);
            findCombinations(i + 1, n, k - 1, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int start = 1;

        findCombinations(start, n, k, temp, ans);

        return ans;
    }
};