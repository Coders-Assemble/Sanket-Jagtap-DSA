#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC => O(nlogn)
// SC => O(1)

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int i = 0;
        int j = tokens.size() - 1;
        int score = 0;
        int maxScore = 0;

        while (i <= j)
        {
            if (power >= tokens[i])
            {
                power -= tokens[i];
                score++;
                i++;
                maxScore = max(score, maxScore);
            }
            else if (score > 0)
            {
                score--;
                power += tokens[j];
                j--;
            }
            else
            {
                return maxScore;
            }
        }
        return maxScore;
    }
};