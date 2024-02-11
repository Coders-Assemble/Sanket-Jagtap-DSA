#include <iostream>
#include <queue>
using namespace std;

// Using Two Queues
// TC => O(n)
// SC => O(n)

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {
    }

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            int front = q1.front();
            q1.pop();
            q2.push(front);
        }

        while (!q2.empty())
        {
            int front = q2.front();
            q2.pop();
            q1.push(front);
        }
    }

    int pop()
    {
        int top = q1.front();
        q1.pop();
        return top;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

// Using Single Queue
// TC => O(n)
// SC => O(n)

class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }

    int pop()
    {
        int front = q.front();
        q.pop();
        return front;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};
