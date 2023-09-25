#include <iostream>
#include <vector>
using namespace std;

// Brute Force
// TC => O(n^2)
// SC => O(1)

bool ls(vector<int> &arr, int num)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size();
    int longest = 1;

    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int count = 1;

        while (ls(a, x + 1))
        {
            x = x + 1;
            count = count + 1;
        }
        longest = max(longest, count);
    }
    return longest;
}