#include <iostream>
#include <string>
using namespace std;

// TC => O(N)
// SC => O(1)

string reverseOnlyLetters(string s)
{
    int n = s.length();

    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
        if (isalpha(s[i]) && isalpha(s[j]))
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        else if (!isalpha(s[i]))
        {
            i++;
        }
        else if (!isalpha(s[j]))
        {
            j--;
            ;
        }
    }
    return s;
}

int main()
{
    string str = "Test1ng-Leet=code-Q!";

    string ans = reverseOnlyLetters(str);

    cout <<"Reversed string after reversing only letters: "<<ans << endl;

    return 0;
}