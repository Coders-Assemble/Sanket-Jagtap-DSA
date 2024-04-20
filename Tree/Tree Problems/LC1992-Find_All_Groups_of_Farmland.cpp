#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(1)

class Solution
{
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>> &land, int i, int j, int &r2, int &c2, int m, int n)
    {
        land[i][j] = 0;

        r2 = max(r2, i);
        c2 = max(c2, j);

        for (auto dir : directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && land[i_][j_] == 1)
            {
                dfs(land, i_, j_, r2, c2, m, n);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> ans;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (land[i][j] == 1)
                {
                    int r1 = i;
                    int c1 = j;
                    int r2 = -1;
                    int c2 = -1;

                    dfs(land, i, j, r2, c2, m, n);
                    ans.push_back({r1, c1, r2, c2});
                }
            }
        }
        return ans;
    }
};