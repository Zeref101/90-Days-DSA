#include <iostream>
#include <vector>
using namespace std;

bool checkPath(int newx, int newy, int n, vector<vector<int>> visited, vector<vector<int>> &m)
{
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && visited[newx][newy] == 0 && m[newx][newy] == 1)
    {
        return true;
    }
    return false;
}

void MazeSolve(vector<vector<int>> visited, vector<vector<int>> &m, int x, int y, vector<string> &ans, string path, int n)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    // * DOWN

    int newx = x + 1;
    int newy = y;
    if (checkPath(newx, newy, n, visited, m))
    {
        path.push_back('D');
        MazeSolve(visited, m, newx, newy, ans, path, 4);
        path.pop_back();
    }
    // * LEFT
    newx = x;
    newy = y - 1;
    if (checkPath(newx, newy, n, visited, m))
    {
        path.push_back('L');
        MazeSolve(visited, m, newx, newy, ans, path, 4);
        path.pop_back();
    }
    // * UP
    newx = x - 1;
    newy = y;
    if (checkPath(newx, newy, n, visited, m))
    {
        path.push_back('U');
        MazeSolve(visited, m, newx, newy, ans, path, 4);
        path.pop_back();
    }
    // * RIGHT
    newx = x;
    newy = y + 1;
    if (checkPath(newx, newy, n, visited, m))
    {
        path.push_back('R');
        MazeSolve(visited, m, newx, newy, ans, path, 4);
        path.pop_back();
    }
}

int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    vector<vector<int>> visited = m;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            visited[i][j] = 0;
        }
    }
    int x = 0;
    int y = 0;
    vector<string> ans;
    string path = "";
    MazeSolve(visited, m, x, y, ans, path, 4);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}