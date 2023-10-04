#include <iostream>
#include <vector>
using namespace std;

// // Type - 1
// Given row and column, Find the element at that place
// TC => O(r)
// SC => O(1)

int findElementInPascalTriangle(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
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

// Type - 2
// Print any Nth row of Pascal's Triangle
// TC => O(N)
// SC => O(1)

void ansRow(int n){
    long long ans = 1;
    cout<<ans<<" ";
    for(int i=1; i<n; i++){
        ans = ans * (n-i);
        ans = ans / i;
        cout<<ans<<" ";
    }
    cout<<endl;
}

int main(){

    ansRow(5);

    return 0;
}
