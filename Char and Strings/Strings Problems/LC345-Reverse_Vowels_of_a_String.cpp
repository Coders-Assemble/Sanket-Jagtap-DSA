#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        int i = 0;
        int j = s.size() - 1;

        while (i <= j)
        {
            if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') && (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U'))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'))
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return s;
    }
};

class Solution
{
public:
    bool isVowel(char a)
    {

        string str = "aeiouAEIOU";

        return (str.find(a) != string::npos);
    }

    string reverseVowels(string s)
    {
        int i = 0;
        int j = s.size() - 1;

        while (i <= j)
        {
            if (isVowel(s[i]) && isVowel(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if (!isVowel(s[i]))
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return s;
    }
};

class Solution
{
public:
    bool isVowel(char ch)
    {

        ch = tolower(ch);

        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s)
    {
        int i = 0;
        int j = s.size() - 1;

        while (i <= j)
        {
            if (isVowel(s[i]) && isVowel(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if (isVowel(s[i]) == 0)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return s;
    }
};