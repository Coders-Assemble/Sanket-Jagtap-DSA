#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve(int open, int close, vector<string> &ans, string output)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(output);
            return;
        }

        if (open > 0)
        {
            output.push_back('(');
            solve(open - 1, close, ans, output);
            // Backtracking
            output.pop_back();
        }

        if (close > open)
        {
            output.push_back(')');
            solve(open, close - 1, ans, output);
            // Backtracking
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string output = "";
        int open = n;
        int close = n;
        solve(open, close, ans, output);
        return ans;
    }
};

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> v;
        int open = n;
        int close = n;
        string op = "";
        solve(open, close, op, v);
        return v;
    }

private:
    void solve(int open, int close, string op, vector<string> &v)
    {
        if (open == 0 && close == 0)
        {
            v.push_back(op);
            return;
        }

        if (open != 0)
        {
            string op1 = op;
            op1.push_back('(');
            solve(open - 1, close, op1, v);
        }

        if (close > open)
        {
            string op2 = op;
            op2.push_back(')');
            solve(open, close - 1, op2, v);
        }
    }
};