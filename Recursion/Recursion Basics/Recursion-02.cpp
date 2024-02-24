#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int climbStairs(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    int ans = climbStairs(n - 1) + climbStairs(n - 2);
    return ans;
}

void printArray(int arr[], int n, int i)
{
    if (i >= n)
        return;

    cout << arr[i] << " ";

    printArray(arr, n, i + 1);
}

void findMax(int arr[], int n, int i, int &maxi)
{
    if (i >= n)
        return;

    maxi = max(arr[i], maxi);

    findMax(arr, n, i + 1, maxi);
}

void findMin(int arr[], int n, int i, int &mini)
{
    if (i >= n)
    {
        return;
    }

    mini = min(arr[i], mini);

    findMin(arr, n, i + 1, mini);
}

void checkKey(string &str, int &n, int i, char key, vector<int> &ans)
{
    if (i >= n)
    {
        return;
    }

    if (str[i] == key)
    {
        ans.push_back(i);
    }

    return checkKey(str, n, i + 1, key, ans);
}

void printDigits(int number, vector<int> &ans)
{
    if (number == 0)
    {
        return;
    }

    int newValueOfN = number/10;
    printDigits(newValueOfN, ans);

    int digit = number % 10;
    ans.push_back(digit);
    
}

int main()
{
    // int n;
    // cout << "Enter the value of n: ";
    // cin >> n;

    // int ans = climbStairs(n);
    // cout << "Ans is: " << ans << endl;

    // int arr[5] = {10, 20, 30, 40, 50};
    // int n = 5;
    // int i = 0;

    // printArray(arr, n, i);

    // int arr[7] = {10, 20, 6, 40, 50, 70, 25};
    // int n = 7;
    // int i = 0;
    // int maxi = INT_MIN;
    // int mini = INT_MAX;

    // findMax(arr, n, i, maxi);
    // findMin(arr, n, i, mini);
    // cout << "Max element is: " << maxi << endl;
    // cout << "Min element is: " << mini << endl;

    // string str = "sanketjagtap";
    // int n = str.size();
    // int i = 0;
    // char key = 'a';
    // vector<int> ans;

    // checkKey(str, n, i, key, ans);
    // cout << "Printing occurences" << endl;
    // if (ans.size() == 0)
    // {
    //     cout << "Character " << key << " is not present" << endl;
    //     return 0;
    // }

    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    int number = 7463;
    vector<int> ans;

    printDigits(number, ans);
    // reverse(ans.begin(), ans.end());
    cout << "Printing digits" << endl;
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}