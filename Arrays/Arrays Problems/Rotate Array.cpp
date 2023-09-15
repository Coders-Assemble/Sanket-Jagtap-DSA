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
