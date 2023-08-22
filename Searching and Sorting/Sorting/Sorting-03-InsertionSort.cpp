#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int round = 1; round < n; round++)
    {
        int val = arr[round];
        int j = round - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > val)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = val;
    }
}

int main()
{
    // vector<int> arr{10, 1, 7, 6, 14, 9};
    vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    insertionSort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}