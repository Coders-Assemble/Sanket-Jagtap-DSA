#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void letterCombinations_helper(string &digits, vector<string> &letters, int ind, string &output, vector<string> &ans)
    {
        if (ind >= digits.size())
        {
            ans.push_back(output);
            return;
        }

        string temp = letters[digits[ind] - '0'];

        for (int i = 0; i < temp.size(); i++)
        {
            output.push_back(temp[i]);
            letterCombinations_helper(digits, letters, ind + 1, output, ans);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        vector<string> ans;
        string output;
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinations_helper(digits, letters, 0, output, ans);
        return ans;
    }
};