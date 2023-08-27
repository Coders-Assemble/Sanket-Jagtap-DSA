#include <iostream>
using namespace std;

int main()
{
    // // Declaration
    // int arr[2][2];

    // // Initialization
    // int brr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // // Printing single element
    // cout << brr[2][2] << endl;

    // // Printing all elements
    // // Row-wise Printing
    // cout << "Printing row-wise " << endl;
    // for (int i = 0; i < 3; i++) {
    //   for (int j = 0; j < 3; j++) {
    //     cout << brr[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;

    // // Column-wise Printing
    // cout << "Printing column-wise " << endl;
    // for (int i = 0; i < 3; i++) {
    //   for (int j = 0; j < 3; j++) {
    //     cout << brr[j][i] << " ";
    //   }
    //   cout << endl;
    // }

    int arr[3][3]; // = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int row = 3;
    int column = 3;

    // Taking input
    cout << "Taking input row-wise" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Printing row-wise" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Taking input column-wise" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> arr[j][i];
        }
    }

    cout << "Printing column-wise" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // cout << "Taking input column-wise" << endl;
    // for (int i = 0; i < row; i++) {
    //   for (int j = 0; j < column; j++) {
    //     cin >> arr[i][j];
    //   }
    // }

    // cout << "Printing column-wise" << endl;
    // for (int i = 0; i < row; i++) {
    //   for (int j = 0; j < column; j++) {
    //     cout << arr[j][i] << " ";
    //   }
    //   cout << endl;
    // }

    return 0;
}