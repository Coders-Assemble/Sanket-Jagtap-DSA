#include <iostream>
#include <string.h>
using namespace std;

int getLength(char ch[])
{
    int length = 0;
    int i = 0;

    while (ch[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}

void reverseCharArray(char name[])
{
    int i = 0;
    int n = getLength(name);
    int j = n - 1;

    while (i <= j)
    {
        swap(name[i], name[j]);
        i++;
        j--;
    }
}

void replaceSpaces(char sentence[])
{
    int n = strlen(sentence);

    for (int i = 0; i < n; i++)
    {
        if (sentence[i] == ' ')
        {
            sentence[i] = '@';
        }
    }
}

bool checkPalindrome(char word[])
{
    int i = 0;
    int n = strlen(word);
    int j = n - 1;

    while (i <= j)
    {
        if (word[i] != word[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

int main()
{
    // Length of array
    // char ch[50];
    // cin >> ch;
    // cout << "Length is: " << getLength(ch) << endl;
    // cout << "Length is: " << strlen(ch) << endl;

    // cout<<"Before reverse: "<<ch<<endl;
    // reverseCharArray(ch);
    // cout<<"After reverse: "<<ch<<endl;

    // char sentence[100];
    // cin.getline(sentence, 100);

    // cout << "Printing string before replacing spaces: " << sentence << endl;
    // replaceSpaces(sentence);
    // cout << "Printing string after replacing spaces: " << sentence << endl;

    // Palindrome
    // char word[50] = "racecar";

    // cout << "The given string is palindrome: " << checkPalindrome(word) << endl;

    return 0;
}