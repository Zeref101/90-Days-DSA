#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int row, int col, char val, vector<vector<char>> &sudoku, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (sudoku[row][i] == val)
        {
            return false;
        }
        if (sudoku[i][col] == val)
        {
            return false;
        }
        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>> &board)
{
    int n = board[0].size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] == '.')
            {
                for (char val = '1'; val <= '9'; val++)
                {
                    if (isSafe(row, col, val, board, n))
                    {
                        board[row][col] = val;

                        bool if_possible = solve(board);
                        if (if_possible)
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solve(board);
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}
