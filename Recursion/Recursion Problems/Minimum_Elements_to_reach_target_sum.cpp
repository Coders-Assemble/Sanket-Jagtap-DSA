#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minimumElements(int arr[], int n, int target)
{
    if (target == 0)
        return 0;

    if (target < 0)
        return INT_MAX;

    int minEl = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int ans = minimumElements(arr, n, target - arr[i]);
        if (ans != INT_MAX)
            minEl = min(minEl, ans + 1);
    }
    return minEl;
}

int main()
{
    int arr[] = {1, 2, 3};
    int target = 5;

    int ans = minimumElements(arr, 3, target);

    cout << "Answer is " << ans << endl;

    return 0;
}