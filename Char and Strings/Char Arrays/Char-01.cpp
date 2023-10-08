#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    // Method 1 to take input in char array
    // char name[10];

    // cout << "Enter Your Name : ";
    // cin >> name;

    // cout << "Your name is : " << name << endl;

    // Method 2 to take input in char array
    // char ch[10];

    // ch[0] = 'a';
    // ch[1] = 'b';
    // cin >> ch[2];

    // cout << ch[0] << ch[1] << ch[2] << endl;

    // cin input string with space in between
    char arr[10];

    // // cin >> arr;
    // // getline(cin, arr);
    cin.getline(arr, 50);

    cout << arr << endl;

    return 0;
}