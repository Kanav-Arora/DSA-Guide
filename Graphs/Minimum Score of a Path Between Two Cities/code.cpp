#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INT_MAX 1e9

int mid(int a, int b)
{
    return a < b ? a : b;
}

int minScore(int n, vector<vector<int>> &roads)
{
    int ans = INT_MAX;
    vector<vector<pair<int, int>>> gr(n + 1);
    for (auto i : roads)
    {
        int u = i[0];
        int v = i[1];
        int edge = i[3];
        gr[u].push_back({v, edge});
        gr[v].push_back({u, edge});
    }

    vector<int> vis(n + 1, 0);
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        for (auto &[v, dis] : gr[node])
        {
            ans = min(ans, dis);
            if (vis[v] == 0)
            {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

int main()
{

    return 0;
}