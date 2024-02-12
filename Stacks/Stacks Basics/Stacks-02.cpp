#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    // Data Members
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    // Member Functions

    void push(int data)
    {
        if (size - top > 1)
        {
            // Space available
            // Insert
            top++;
            arr[top] = data;
        }
        else
        {
            // Space not available
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            // Stack is empty
            cout << "Stack Underflow, Can't delete element" << endl;
        }
        else
        {
            // Stack is not empty
            top--;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "There is no element in Stack" << endl;
        }
        else
        {
            return arr[top];
        }
    }

    int getSize()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    // Creation
    Stack s(5);

    // Insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // s.push(60); // Stack Overflow, Can,t add element

    // Printing elements of stack
    while (!s.isEmpty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
    cout << endl;

    cout << "Size of stack: " << s.getSize() << endl;

    // s.pop(); // Stack Underflow, Can't delete element

    return 0;
}