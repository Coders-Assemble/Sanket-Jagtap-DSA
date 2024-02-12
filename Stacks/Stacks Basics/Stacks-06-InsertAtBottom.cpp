#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &s, int target)
{
    // Base Case
    if (s.empty())
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();

    // Recursive Call
    solve(s, target);

    // Backtrack
    s.push(topElement);
}

void insertAtBottom(stack<int> &s)
{
    if (s.empty())
    {
        cout << "Stack is empty" << endl;
        return;
    }

    int target = s.top();
    s.pop();

    solve(s, target);
}

int main()
{

    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    insertAtBottom(s);

    cout << "Printing elements of stack: ";

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}