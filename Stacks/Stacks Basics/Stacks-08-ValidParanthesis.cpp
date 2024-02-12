#include <iostream>
#include <stack>
using namespace std;

bool validParanthesis(string str)
{
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // Opening Brackets
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else
        {
            // Closing Brackets
            if (!s.empty())
            {
                char topCh = s.top();
                if (ch == ')' && topCh == '(')
                {
                    s.pop();
                }
                else if (ch == ']' && topCh == '[')
                {
                    s.pop();
                }
                else if (ch == '}' && topCh == '{')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    string str = "([])";

    bool ans = validParanthesis(str);

    if (ans)
    {
        cout << "The Paranthesis are valid" << endl;
    }
    else
    {
        cout << "The Paranthesis are not valid" << endl;
    }

    return 0;
}