#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(char first, char second)
{
    return first > second;
}

bool compare(int a, int b)
{
    return a > b;
}

bool strCmp(string a, string b)
{
    return a > b;
}

int main()
{
    string str = "SANKET";

    sort(str.begin(), str.end(), cmp);

    cout << str << endl;

    vector<int> v{4, 3, 5, 1, 2};

    sort(v.begin(), v.end(), compare);

    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<string> s{"Rohit", "Virat", "Sachin", "Dhoni", "Rahul"};

    sort(s.begin(), s.end(), strCmp);

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}