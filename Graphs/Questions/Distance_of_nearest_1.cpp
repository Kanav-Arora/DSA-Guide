#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<vector<int>> ans(m, vector<int>(n, 0));

    queue<pair<pair<int, int>, int>> q; // row,col step

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                q.push({{i, j}, 0});
                visited[i][j] = 1;
            }
        }
    }

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        pair<pair<int, int>, int> front = q.front();
        q.pop();
        int row = front.first.first;
        int col = front.first.second;
        int step = front.second;
        ans[row][col] = step;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && visited[nrow][ncol] == 0)
            {
                visited[nrow][ncol] = 1;
                q.push({{nrow, ncol}, step + 1});
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}