#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmallerElement(vector<int> &input)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());
    for (int i = 0; i < input.size(); i++)
    {
        int curr = input[i];

        // Pop elements from stack until you don't get element smaller than current element
        while (s.top() >= curr)
        {
            s.pop();
        }

        // Found smaller element -> Store in ans vector
        ans[i] = s.top();

        // Push current element in the stack
        s.push(curr);
    }
    return ans;
}

vector<int> prevSmallerElement2(vector<int> &input)
{
    int n = input.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && input[st.top()] > input[i])
        {
            ans[st.top()] = input[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> input;

    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    input.push_back(3);

    vector<int> ans = prevSmallerElement(input);
    vector<int> ans1 = prevSmallerElement2(input);

    cout << "Printing the Output vector" << endl;
    for (int i = 0; i < input.size(); i++)
    {
        cout << ans[i] << " ";
    }

    for (int i = 0; i < input.size(); i++)
    {
        cout << ans1[i] << " ";
    }

    return 0;
}