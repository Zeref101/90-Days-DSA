#include <iostream>
#include <vector>
using namespace std;

// Function to check if it is safe to place a queen at board[row][col]
bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    // Check if there is a queen in the same row
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }
    // Check if there is a queen in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    // Check if there is a queen in the lower left diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    // It is safe to place a queen at board[row][col]
    return true;
}

// Function to add a solution to the answer vector
void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> solution;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            solution.push_back(board[i][j]);
        }
    }
    ans.push_back(solution);
}

// Function to solve the N-Queens problem using backtracking
void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    if (col == n)
    {
        addSolution(board, ans, n);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            // Backtracking
            board[row][col] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, ans, board, n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}