#include <iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int> &arr, int &n, int i)
{
    // If i reached at the last index, it means array is sorted
    // Also we can't access the arr[i+1] element if i is at the last index
    if (i == n - 1)
    {
        return true;
    }

    // If at any point arr[i] > arr[i+1], it means array is not sorted
    if (arr[i + 1] < arr[i])
    {
        return false;
    }

    // Recursive call
    return checkSorted(arr, n, i + 1);
}

int binarySearch(vector<int> &arr, int &target, int s, int e)
{
    // Base Case
    // If s crosses e it means, target not found
    if (s > e)
        return -1;

    int mid = (s + e) / 2;

    if (arr[mid] == target)
        return mid;

    // Recursive Call
    if (arr[mid] < target)
        // If target is greater than arr[mid] then search in right part of array
        return binarySearch(arr, target, mid + 1, e);
    else
        // If target is lesser than arr[mid] then search in left part of array
        return binarySearch(arr, target, s, mid - 1);
}

void printSubsequences(string &str, string output, vector<string> &v, int i)
{
    // If i is greater than the size of str, it means the input string is exhausted
    // So push the output string in the ans vector and return
    if (i == str.length())
    {
        v.push_back(output);
        return;
    }

    // Exclude the current character
    printSubsequences(str, output, v, i + 1);

    // Include the current character
    output.push_back(str[i]);
    printSubsequences(str, output, v, i + 1);
}

int main()
{

    // vector<int> v = {10, 20, 30, 40, 50, 60};
    // int n = v.size();

    // bool isSorted = checkSorted(v, n, 0);

    // if (isSorted)
    // {
    //     cout << "Array is Sorted" << endl;
    // }
    // else
    // {
    //     cout << "Array is not Sorted" << endl;
    // }

    // vector<int> v = {10, 20, 30, 40, 50, 60};
    // int n = v.size();
    // int target = 40;
    // int s = 0;
    // int e = n - 1;

    // int ind = binarySearch(v, target, s, e);

    // if (ind == -1)
    // {
    //     cout << "Target " << target << " is not present" << endl;
    // }
    // else
    // {
    //     cout << "Target " << target << " is present at index " << ind << endl;
    // }

    string str = "abcd";
    string output = "";
    vector<string> v;

    printSubsequences(str, output, v, 0);

    cout << "Printing Subsequences" << endl;

    for (auto el : v)
    {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}