#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int round = 1; round < n; round++)
    {
        bool swapped = false;
        for (int j = 0; j < n - round; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            // Sorted
            break;
        }
    }
}

int main()
{

    // vector<int> arr{8, 4, 13, 22, 11};
    vector<int> arr{10, 1, 7, 6, 14, 9};

    BubbleSort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}