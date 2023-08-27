#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<vector<int>> arr;

    // vector<int> a{1, 2, 3};
    // vector<int> b{8, 6, 4};
    // vector<int> c{7, 6, 2};

    // arr.push_back(a);
    // arr.push_back(b);
    // arr.push_back(c);

    // for (int i = 0; i < arr.size(); i++) {
    //   for (int j = 0; j < arr[0].size(); j++) {
    //     cout << arr[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    // int row = 5;
    // int col = 5;
    // vector<vector<int>> arr(row, vector<int>(col, -8));

    // cout << arr[2][3] << endl;

    // for (int i = 0; i < arr.size(); i++) {
    //   for (int j = 0; j < arr[0].size(); j++) {
    //     cout << arr[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    int row = 3;
    int col = 4;
    vector<vector<int>> arr(row, vector<int>(col));

    cout << "Enter the elements of array : " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << endl;

    cout << "Printing the array : " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}