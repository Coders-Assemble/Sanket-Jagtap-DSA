#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Recursive Approach
// Segmentation Fault
// TC => O(N)
// SC => O(N)

class Solution
{
public:
    void BST(int arr[], int &index, int lower, int upper, int &N)
    {
        if (index == N || arr[index] < lower || arr[index] > upper)
            return;

        int value = arr[index++];
        BST(arr, index, lower, value, N);
        BST(arr, index, value, upper, N);
    }

    int canRepresentBST(int arr[], int N)
    {
        int index = 0;
        BST(arr, index, INT_MIN, INT_MAX, N);
        return index == N;
    }
};

// Iterative Approach
// TC => O(N)
// SC => O(N)

class Solution
{
public:
    int canRepresentBST(int arr[], int N)
    {
        stack<int> lower, upper;
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        int lowerBound, upperBound;

        for (int i = 0; i < N; i++)
        {
            if (arr[i] < lower.top())
                return 0;

            while (arr[i] > upper.top())
            {
                lower.pop();
                upper.pop();
            }

            lowerBound = lower.top();
            upperBound = upper.top();
            lower.pop();
            upper.pop();

            lower.push(arr[i]);
            upper.push(upperBound);
            lower.push(lowerBound);
            upper.push(arr[i]);
        }
        return 1;
    }
};