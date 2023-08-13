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
            // left search
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

int main()
{

    vector<int> v{1, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 7, 8, 9};
    int target = 4;

    int indexOfElement = lastOcc(v, target);

    cout << "Last occurence of " << target << " is at " << indexOfElement << endl;

    // Using inbuild function - upper_bound

    auto ans2 = upper_bound (v.begin(), v.end(), target);
    cout << "Ans 2: " << (ans2 - v.begin()) << endl;

    return 0;
}