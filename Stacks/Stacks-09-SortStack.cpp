#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &s, int target)
{
    // Base case
    if (s.empty())
    {
        s.push(target);
        return;
    }

    if (s.top() >= target)
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();

    // Recursive Call
    insertSorted(s, target);

    // Backtrack
    s.push(topElement);
}

void sortStack(stack<int> &s)
{
    // Base case
    if (s.empty())
    {
        return;
    }

    int topElement = s.top();
    s.pop();

    // Recursive Call
    sortStack(s);

    // Backtrack
    insertSorted(s, topElement);
}

int main()
{

    stack<int> s;

    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    sortStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}