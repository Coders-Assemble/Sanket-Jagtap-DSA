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

int main()
{
    vector<int> input;

    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    input.push_back(3);

    vector<int> ans = prevSmallerElement(input);

    cout << "Printing the Output vector" << endl;
    for (int i = 0; i < input.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}