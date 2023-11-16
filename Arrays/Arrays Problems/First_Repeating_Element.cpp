#include <iostream>
#include <map>
using namespace std;

// Brute force Approach (TLE) => Using two nested loops by comparing every element
// TC => O(n^2)
// SC => O(1)

// Optimal Approach => Using Hashmap
// TC => O(n)
// SC => O(n)

class Solution
{
public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n)
    {
        map<int, int> mpp;

        for (int i = 0; i < n; i++)
        {
            mpp[arr[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (mpp[arr[i]] > 1)
            {
                return i + 1;
            }
        }
        return -1;
    }
};
