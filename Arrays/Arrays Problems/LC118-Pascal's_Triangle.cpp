#include <iostream>
#include <vector>
using namespace std;

// Given row and column, Find the element at that place
int findElementInPascalTriangle(int r, int c)
{
    int res = 1;
    for (int i = 0; i < c; i++)
    {
        res = res * (r - i);
        res = res / (i + 1);
    }
    return res;
}

int main()
{
    int r = 5;
    int c = 3;

    int ans = findElementInPascalTriangle(r - 1, c - 1);
    cout << "Element at " << r << "," << c << " is " << ans << endl;

    return 0;
}