#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &input)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());
    for (int i = input.size() - 1; i >= 0; i--)
    {
        int curr = input[i];

        while (s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

vector<int> nextSmallerElementRight(vector<int> &input)
{
    int n = input.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
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

    vector<int> ans = nextSmallerElement(input);
    vector<int> ans1 = nextSmallerElementRight(input);

    cout << "Printing" << endl;
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