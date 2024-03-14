#include <iostream>
#include <vector>
using namespace std;

void printSoution(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n)
{
    // Checking for left of current row
    int i = row;
    int j = col;

    while (j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        j--;
    }

    // Checking for upper left diagonal
    i = row;
    j = col;

    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i--, j--;
    }

    // Checking for bottom left diagonal
    i = row;
    j = col;

    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void solve(vector<vector<char>> &board, int col, int n)
{
    if (col >= n)
    {
        printSoution(board, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(board, col + 1, n);
            board[row][col] = '-';
        }
    }
}

int main()
{
    int n = 5;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;

    solve(board, col, n);

    return 0;
}

class Solution
{
private:
    bool isSafe(int row, int col, vector<vector<char>> &board, int n)
    {
        // Checking for left of current row
        int i = row;
        int j = col;

        while (j >= 0)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
            j--;
        }

        // Checking for upper left diagonal
        i = row;
        j = col;

        while (i >= 0 && j >= 0)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
            i--, j--;
        }

        // Checking for bottom left diagonal
        i = row;
        j = col;

        while (i < n && j >= 0)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    void solve(vector<vector<char>> &board, int col, int n, vector<vector<string>> &ans)
    {
        if (col >= n)
        {
            vector<string> op;
            for (int i = 0; i < n; i++)
            {
                string row(board[i].begin(), board[i].end());
                op.push_back(row);
            }
            ans.push_back(op);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(board, col + 1, n, ans);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        int col = 0;

        solve(board, col, n, ans);
        return ans;
    }
};