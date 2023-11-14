#include <iostream>
#include <vector>
using namespace std;

// Dutch National Flag Algorithm
// TC => O(N)
// SC => O(1)

void moveAllNegToLeft(vector<int> &v)
{
    int low = 0;
    int high = v.size() - 1;

    while (low < high)
    {
        if (v[low] < 0)
        {
            low++;
        }
        else if (v[high] > 0)
        {
            high--;
        }
        else
        {
            swap(v[low], v[high]);
        }
    }
}

int main()
{

    // vector<int> v{-1, 2, 3, -4, 5, -6, 7};
    vector<int> v{1, 0, -1, -2, -3, -4, -5, -6, -7};

    moveAllNegToLeft(v);

    for (auto it : v)
    {
        cout << it << " ";
    }

    return 0;
}