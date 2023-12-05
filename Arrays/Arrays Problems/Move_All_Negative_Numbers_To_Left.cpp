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

// TC => O(n)
// SC => O(1)

vector<int> separateNegativeAndPositive(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    int j = 1;

    while (j < n)
    {
        if (nums[i] < 0)
        {
            i++;
        }
        else if (nums[j] < 0)
        {
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
        else if (nums[j] >= 0)
        {
            j++;
        }

        if (i >= j)
        {
            j = i + 1;
        }
    }
    return nums;
}