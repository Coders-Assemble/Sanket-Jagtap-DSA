#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC => O(nlogn) + O(n)
// SC => O(1)

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();

        if (n == 1)
            return 1;

        sort(points.begin(), points.end());

        int arrows = 1;
        vector<int> commonInterval = points[0];

        for (int i = 1; i < n; i++)
        {
            if (points[i][0] <= commonInterval[1])
            {
                commonInterval[0] = max(commonInterval[0], points[i][0]);
                commonInterval[1] = min(commonInterval[1], points[i][1]);
            }
            else
            {
                commonInterval = points[i];
                arrows++;
            }
        }

        return arrows;
    }
};