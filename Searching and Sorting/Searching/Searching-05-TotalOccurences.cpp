#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lastOcc(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;

    int mid = start + ((end - start) / 2);
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == target)
        {
            // index store
            ans = mid;
            // right search
            start = mid + 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        mid = start + ((end - start) / 2);
    }
    return ans;
}

int firstOcc(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;

    int mid = start + ((end - start) / 2);
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == target)
        {
            // index store
            ans = mid;
            // left search
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        mid = start + ((end - start) / 2);
    }
    return ans;
}

int main()
{

    vector<int> v{1, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 7, 8, 9};
    int target = 4;

    cout << "Total occurences: " << lastOcc(v, target) - firstOcc(v, target) + 1 << endl;

    auto lastOcc = upper_bound(v.begin(), v.end(), target);
    auto firstOcc = lower_bound(v.begin(), v.end(), target);
    cout << "Total occurences of an element: " << (lastOcc - v.begin()) - (firstOcc - v.begin()) << endl;

    return 0;
}