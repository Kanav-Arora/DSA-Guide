#include <iostream>
#include<vector>
#include<set>
using namespace std;

void DFS(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, vector<pair<int, int>> &temp)
{
    visited[i][j] = true;

    if (temp.size() == 0)
    {
        temp.push_back({i, j});
    }
    else
    {
        temp.push_back({i - temp[0].first, j - temp[0].second});
    }

    int rowd[] = {-1, 0, 1, 0};
    int cold[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++)
    {
        int nrow = i + rowd[k];
        int ncol = j + cold[k];

        if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == 1 && visited[nrow][ncol] == false)
        {
            DFS(grid, nrow, ncol, visited, temp);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    vector<vector<pair<int, int>>> v;

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && visited[i][j] == false)
            {
                vector<pair<int, int>> temp;
                DFS(grid, i, j, visited, temp);
                temp[0] = {0, 0};
                v.push_back(temp);
            }
        }
    }

    set<vector<pair<int, int>>> st;

    for (auto i : v)
    {
        for (auto j : i)
            cout << "(" << j.first << "," << j.second << ")"
                 << " ";
        cout << endl;
        st.insert(i);
    }

    return st.size();
}

int main()
{

    return 0;
}