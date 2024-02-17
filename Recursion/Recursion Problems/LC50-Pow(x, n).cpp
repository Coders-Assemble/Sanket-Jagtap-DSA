#include <iostream>
#include <vector>
using namespace std;

// TC => O(logn)
// SC => O(logn)

class Solution
{
public:
    double solve(double x, long n)
    {
        if (n == 0)
            return 1;

        if (n < 0)
        {
            return solve(1 / x, -n);
        }

        if (n % 2 == 0)
        {
            return solve(x * x, n / 2);
        }

        return x * solve(x * x, (n - 1) / 2);
    }

    double myPow(double x, int n)
    {
        return solve(x, long(n));
    }
};