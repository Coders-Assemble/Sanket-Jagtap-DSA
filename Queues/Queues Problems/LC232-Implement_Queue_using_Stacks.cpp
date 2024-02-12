#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// TC => for push O(n), for pop, peek, and empty O(1)
// SC => O(n)

class MyQueue
{
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {}

    void push(int x)
    {
        while (!st1.empty())
        {
            int top = st1.top();
            st1.pop();
            st2.push(top);
        }

        st1.push(x);

        while (!st2.empty())
        {
            int top = st2.top();
            st2.pop();
            st1.push(top);
        }
    }

    int pop()
    {
        int top = st1.top();
        st1.pop();
        return top;
    }

    int peek()
    {
        return st1.top();
    }

    bool empty()
    {
        return st1.empty();
    }
};

// TC => for push, empty O(1), for pop, peek O(n)
// SC => O(n)

class MyQueue
{
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {}

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        if (st2.empty())
        {
            while (!st1.empty())
            {
                int temp = st1.top();
                st1.pop();
                st2.push(temp);
            }
        }
        int temp = st2.top();
        st2.pop();
        return temp;
    }

    int peek()
    {
        if (st2.empty())
        {
            while (!st1.empty())
            {
                int temp = st1.top();
                st1.pop();
                st2.push(temp);
            }
        }
        return st2.top();
    }

    bool empty()
    {
        return st1.empty() && st2.empty();
    }
};
