#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int m;

    while (s <= e)
    {
        m = s + (e - s) / 2;

        if (arr[m] == target)
            return m;

        if (arr[m - 1] == target)
            return m - 1;

        if (arr[m + 1] == target)
            return m + 1;

        if (target > arr[m])
            s = m + 2;
        else
            e = m - 2;
    }
    return -1;
}

int main()
{

    vector<int> v{10, 3, 40, 20, 50, 80, 70};

    int target = 40;

    int ans = binarySearch(v, target);

    cout << "The index of " << target << " is " << ans << endl;

    return 0;
}