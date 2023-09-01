#include <iostream>
#include <vector>
using namespace std;

void setMatrixOnes(vector<vector<int>> &MAT, int n, int m)
{
    vector<bool> rowHasOne(n, false);
    vector<bool> colHasOne(m, false);

    // Check each element in the matrix and mark rows and columns that contain 1.
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(MAT[i][j] == 1)
            {
                rowHasOne[i] = true;
                colHasOne[j] = true;
            }
        }
    }

    // Set rows and columns to 1 based on the flags.
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(rowHasOne[i] || colHasOne[j])
            {
                MAT[i][j] = 1;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> MAT(n, vector<int>(m));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> MAT[i][j];
        }
    }

    setMatrixOnes(MAT, n, m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << MAT[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
