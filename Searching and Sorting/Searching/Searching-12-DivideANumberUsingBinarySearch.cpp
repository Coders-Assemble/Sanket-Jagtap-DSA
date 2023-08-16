#include <iostream>
using namespace std;

int divide(int dividend, int divisor)
{
    int s = 0;
    int e = abs(dividend);
    int m;

    int ans = 0;

    while (s <= e)
    {
        m = s + (e - s) / 2;
        if (abs(m * divisor) == abs(dividend))
        {
            ans = m;
            break;
        }
        else if (abs(m * divisor) > abs(dividend))
        {
            e = m - 1;
        }
        else
        {
            ans = m;
            s = m + 1;
        }
    }

    if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
    {
        return -ans;
    }
    else
    {
        return ans;
    }
}

int main()
{

    int dividend = -2147483648;
    int divisor = -1;

    int ans = divide(dividend, divisor);

    cout << "Ans is : " << ans << endl;

    return 0;
}

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        long long s = 0;
        long long e = abs(dividend);
        long long m;

        long long ans = 0;

        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        else if(dividend == INT_MIN && divisor == 1){
            return INT_MIN;
        }

        while (s <= e)
        {
            m = s + (e - s) / 2;
            if (abs(m * divisor) == abs(dividend))
            {
                ans = m;
                break;
            }

            if (abs(m * divisor) > abs(dividend))
            {
                e = m - 1;
            }
            else
            {
                ans = m;
                s = m + 1;
            }
        }

        if (dividend < 0 && divisor < 0 || dividend > 0 && divisor > 0)
        {
            return ans;
        }
        else
        {
            return -ans;
        }
    }
};