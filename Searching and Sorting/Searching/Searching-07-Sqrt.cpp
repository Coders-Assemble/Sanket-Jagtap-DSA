#include <iostream>
using namespace std;

int findSqrt(int n)
{
    int target = n;
    int start = 0;
    int end = n;
    int mid;
    int ans = -1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (mid * mid == target)
        {
            return mid;
        }

        if (mid * mid > target)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    int ans = findSqrt(n);

    cout << "Squre root of " << n << " is " << ans << endl;

    int precision;
    cout << "Enter the number of floating digits in precision: ";
    cin >> precision;

    double step = 0.1;
    double finalAns = ans;
    for (int i = 0; i < precision; i++)
    {
        for (double j = finalAns; j * j <= n; j = j + step)
        {
            finalAns = j;
        }
        step = step / 10;
    }

    cout << "Final ans is: " << finalAns << endl;

    return 0;
}