#include <iostream>
#include <vector>
using namespace std;

// TC => O(n)
// SC => O(n)

void segregateElements(vector<int> arr)
{
    int n = arr.size();
    vector<int> temp(n);
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            temp[idx] = arr[i];
            idx++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            temp[idx] = arr[i];
            idx++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }

    for (auto it : arr)
    {
        cout << it << " ";
    }
}

int main()
{
    vector<int> arr{1, -1, 3, 2, -7, -5, 11, 6};

    segregateElements(arr);

    return 0;
}
