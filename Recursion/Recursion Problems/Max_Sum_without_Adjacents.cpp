#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void solve(vector<int> &arr, int i, int sum, int &maxSum)
{
    if (i >= arr.size())
    {
        maxSum = max(maxSum, sum);
        return;
    }

    solve(arr, i + 2, sum + arr[i], maxSum);
    solve(arr, i + 1, sum, maxSum);
}

int main()
{
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    int sum = 0;
    int maxSum = INT_MIN;
    solve(arr, 0, sum, maxSum);

    cout << "maxSummum sum is: " << maxSum << endl;

    return 0;
}