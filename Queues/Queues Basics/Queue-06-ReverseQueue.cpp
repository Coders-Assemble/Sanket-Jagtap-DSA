#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseUsingStack(queue<int> &q)
{
    stack<int> s;

    while (!q.empty())
    {
        int element = q.front();
        q.pop();

        s.push(element);
    }

    while (!s.empty())
    {
        int element = s.top();
        s.pop();

        q.push(element);
    }
}

void reverseUsingRecursion(queue<int> &q)
{
    // Base case
    if (q.empty())
    {
        return;
    }

    // Step A
    int temp = q.front();
    q.pop();

    // Step B
    reverseUsingRecursion(q);

    // Step C
    q.push(temp);
}

int main()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);

    // reverseUsingStack(q);
    reverseUsingRecursion(q);

    // cout << "Printing Queue after reverse using stack" << endl;
    cout << "Printing Queue after reversing recursively" << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}