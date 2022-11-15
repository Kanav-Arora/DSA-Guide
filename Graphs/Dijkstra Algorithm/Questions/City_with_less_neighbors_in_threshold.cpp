#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findCity(int n, int m, vector<vector<int>> &edges,
             int distanceThreshold)
{

    vector<vector<int>> mat(n, vector<int>(n, INT_MAX));
    for (auto i : edges)
    {
        mat[i[0]][i[1]] = i[2];
        mat[i[1]][i[0]] = i[2];
    }

    for (int i = 0; i < n; i++)
        mat[i][i] = 0;

    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][via] == INT_MAX || mat[via][j] == INT_MAX)
                    continue;

                mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
            }
        }
    }

    int cntcity = n;
    int cityno = -1;

    for (int city = 0; city < n; city++)
    {
        int cnt = 0;
        for (int adj = 0; adj < n; adj++)
        {
            if (city == adj)
                continue;

            if (mat[city][adj] <= distanceThreshold)
                cnt++;
        }

        if (cnt <= cntcity)
        {
            cntcity = cnt;
            cityno = city;
        }
    }

    return cityno;
}

int main()
{

    return 0;
}