#include <iostream>
using namespace std;

int factorial(int n)
{
    // Base condition
    if (n == 1)
    {
        return 1;
    }

    // Recursive call
    int ans = n * factorial(n - 1);

    return ans;
}

void reverseCounting(int n)
{
    // Base condition
    if (n == 0)
    {
        return;
    }

    // Processing
    cout << n << " ";

    // Recursive call
    reverseCounting(n - 1);
}

int fib(int n)
{
    // Base case
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    // Recursive relation
    int ans = fib(n - 1) + fib(n - 2);

    return ans;
}

int main()
{

    int n;
    cout << "Enter value of n: ";
    cin >> n;

    // int ans = factorial(n);
    // cout<<"Factorial of "<<n<<" is : "<<ans<<endl;

    // reverseCounting(n);

    int ans = fib(n);
    cout << "The " << n << "th number in fib series is: " << ans << endl;

    return 0;
}