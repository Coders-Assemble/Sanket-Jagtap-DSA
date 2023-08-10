#include <iostream>
using namespace std;

void linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}

int main()
{

    int arr[] = {2, 8, 9, 7, 6, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    linearSearch(arr, size, target);

    return 0;
}