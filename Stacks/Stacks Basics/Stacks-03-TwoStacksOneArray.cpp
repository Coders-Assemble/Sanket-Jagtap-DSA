#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    // Data Members
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    // Member Functions
    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            // Space is not available
            cout << "STACK 1 OVERFLOW" << endl;
        }
        else
        {
            // Space available
            top1++;
            arr[top1] = data;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        {
            // Stack 1 is empty
            cout << "STACK 1 UNDERFLOW" << endl;
        }
        else
        {
            // Stack 1 is not empty
            arr[top1] = 0;
            top1--;
        }
    }

    void push2(int data)
    {
        if (top2 - top1 == 1)
        {
            // Space is not available
            cout << "STACK 2 OVERFLOW" << endl;
        }
        else
        {
            // Space available
            top2--;
            arr[top2] = data;
        }
    }

    void pop2()
    {
        if (top2 == size)
        {
            // Stack 2 is empty
            cout << "STACK 2 UNDERFLOW" << endl;
        }
        else
        {
            // Stack 2 is not empty
            arr[top2] = 0;
            top2++;
        }
    }

    void print()
    {
        cout << endl;
        cout << "Top1: " << top1 << endl;
        cout << "Top2: " << top2 << endl;

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s(10);

    s.push1(10);
    s.print();
    s.push1(20);
    s.print();
    s.push1(30);
    s.print();
    s.push1(40);
    s.print();
    s.push1(50);
    s.print();

    s.push2(100);
    s.print();
    s.push2(90);
    s.print();
    s.push2(80);
    s.print();
    s.push2(70);
    s.print();
    s.push2(60);
    s.print();

    // OVERFLOW CONDITIONS
    // s.push1(500);
    // s.push2(1000);

    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();

    s.push2(150);
    s.print();

    // UNDERFLOW CONDITION
    s.pop1();

    return 0;
}