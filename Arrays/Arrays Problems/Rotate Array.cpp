#include <iostream>
#include <vector>
using namespace std;

// Rotate an Array by 1 place
vector<int> rotateArray(vector<int> &arr, int n)
{
    int temp = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = temp;

    return arr;
}

// Left Rotate - Brute force
// vector<int> rotateArray(vector<int> arr, int k)
// {
//     int n = arr.size();
//     int temp[k];
//     for (int i = 0; i < k; i++)
//     {
//         temp[i] = arr[i];
//     }

//     for (int i = k; i < n; i++)
//     {
//         arr[i - k] = arr[i];
//     }

//     int j = 0;
//     for (int i = n - k; i < n; i++)
//     {
//         arr[i] = temp[j];
//         j++;
//     }
//     return arr;
// }

// Left Rotate - Optimal
vector<int> rotateArray(vector<int> arr, int k)
{
    int n = arr.size();
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.begin() + n);
    reverse(arr.begin(), arr.begin() + n);

    return arr;
}

// Right Rotate - Brute force
// class Solution
// {
// public:
//     void rotate(vector<int> &nums, int k)
//     {
//         int n = nums.size();
//         k = k % n;

//         if (k == 0)
//             return;
//         if (n == 1)
//             return;

//         int temp[k];
//         int j = 0;
//         for (int i = n - k; i < n; i++)
//         {
//             temp[j] = nums[i];
//             j++;
//         }

//         for (int i = n - 1; i >= k; i--)
//         {
//             nums[i] = nums[i - k];
//         }

//         for (int i = 0; i < k; i++)
//         {
//             nums[i] = temp[i];
//         }
//     }
// };

// Right Rotate - Optimal
class Solution
{
public:
    void rotate(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (n == 1)
            return;
        k = k % n;
        if (k == 0)
            return;
        reverse(arr.begin(), arr.begin() + n);
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.begin() + n);
    }
};

