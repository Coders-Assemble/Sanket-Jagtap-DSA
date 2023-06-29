#include <iostream>
#include <stack>
using namespace std;

int main()
{

    // // Creation
    // stack<int> st;

    // // Insertion
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);

    // // Deletion
    // st.pop();

    // // Top of Stack
    // cout << "Top of stack is: " << st.top() << endl;

    // // Size of Stack
    // cout << "Size of Stack is: " << st.size() << endl;

    // // Check empty
    // if (st.empty())
    // {
    //     cout << "Stack is Empty";
    // }
    // else
    // {
    //     cout << "Stack is Not Empty";
    // }

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // Printing elements of stack 
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}