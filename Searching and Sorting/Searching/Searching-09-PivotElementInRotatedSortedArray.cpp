#include <iostream>
#include <vector>
using namespace std;

int findPivotElement(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (start == end)
        {
            return start;
        }

        if ((mid + 1 <= end) && (arr[mid] > arr[mid + 1]))
        {
            return mid;
        }

        if ((mid - 1 >= start) && (arr[mid - 1] > arr[mid]))
        {
            return mid - 1;
        }

        if (arr[start] > arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v{2, 4, 6, 8, 9, 10};

    int ans = findPivotElement(v);

    if (ans == -1)
    {
        cout << "Kuch gadbad hai" << endl;
    }
    else
    {
        cout << "Pivot element " << v[ans] << " found at index " << ans << endl;
    }

    return 0;
}