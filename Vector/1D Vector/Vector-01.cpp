#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // // Create Vector
    // vector<int> v;

    // // cout << "Size of vector is : " << v.size() << endl;
    // // cout << "Capacity of vector is : " << v.capacity() << endl;

    // // Insert
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(7);
    // v.push_back(8);

    // // Printing elements of vector
    // for (int i = 0; i < v.size(); i++) {
    //   cout << v[i] << " ";
    // }
    // cout << endl;

    // // Remove/Delete
    // v.pop_back();

    // // Printing elements of vector
    // for (int i = 0; i < v.size(); i++) {
    //   cout << v[i] << " ";
    // }
    // cout << endl;

    // // Another way to create vector

    // int n;
    // cout << "Enter elements of vector : ";
    // cin >> n;

    // vector<int> v1(n, -1);

    // cout << "Size of v1 is : " << v1.size() << endl;
    // cout << "Capacity of v1 is : " << v1.capacity() << endl;

    // // Printing elements of vector
    // for (int i = 0; i < v1.size(); i++) {
    //   cout << v1[i] << " ";
    // }
    // cout << endl;

    // Another way to create vector

    vector<int> v2{10, 20, 30, 40, 50};

    // Printing elements of vector
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;

    cout << "Vector v2 is empty or not : " << v2.empty() << endl;

    vector<int> v3;
    cout << "Vector v3 is empty or not : " << v3.empty() << endl;

    return 0;
}