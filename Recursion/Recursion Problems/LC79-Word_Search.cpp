#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchNext(vector<vector<char>> &board, string &word, int index, int row, int col, int &m, int &n)
    {
        if (index >= word.size())
        {
            return true;
        }

        if (row < 0 || col < 0 || row == m || col == n || board[row][col] != word[index] || board[row][col] == '$')
        {
            return false;
        }

        char ch = board[row][col];
        board[row][col] = '$';

        bool top = searchNext(board, word, index + 1, row - 1, col, m, n);

        bool right = searchNext(board, word, index + 1, row, col + 1, m, n);

        bool bottom = searchNext(board, word, index + 1, row + 1, col, m, n);

        bool left = searchNext(board, word, index + 1, row, col - 1, m, n);

        board[row][col] = ch;

        return top || right || bottom || left;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        int index = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (searchNext(board, word, index, i, j, m, n))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};