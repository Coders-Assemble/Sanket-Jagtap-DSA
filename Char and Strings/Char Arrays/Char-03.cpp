#include <iostream>
#include <string.h>
using namespace std;

void convertIntoUppercase(char ch[])
{
    int n = strlen(ch);

    for (int i = 0; i < n; i++)
    {
        // if(ch[i] >= 'A' && ch[i] <= 'Z') continue;
        // ch[i] = ch[i] - 'a' + 'A';
         
        // if(ch[i] >= 'a' && ch[i] <= 'z'){
        //     ch[i] = ch[i] - 'a' + 'A';
        // }
    }
}

void convertIntoLowercase(char ch[])
{
    int n = strlen(ch);

    for (int i = 0; i < n; i++)
    {
        // if(ch[i] >= 'a' && ch[i] <= 'z') continue;
        // ch[i] = ch[i] - 'A' + 'a';
         
        if(ch[i] >= 'A' && ch[i] <= 'Z'){
            ch[i] = ch[i] - 'A' + 'a';
        }
    }
}

int main()
{

    // char lowerCaseArr[100] = "SanKet";

    // convertIntoUppercase(lowerCaseArr);

    // cout << "Uppercase array is: " << lowerCaseArr << endl;
    

    char upperCaseArr[100] = "SAnKEt";

    convertIntoLowercase(upperCaseArr);

    cout << "Lowercase array is: " << upperCaseArr << endl;

    return 0;
}