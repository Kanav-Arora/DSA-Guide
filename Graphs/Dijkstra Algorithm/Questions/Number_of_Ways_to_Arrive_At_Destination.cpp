#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pr;

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<pair<int, int>> adj[n];

    for (auto i : roads)
    {
        int u = i[0];
        int v = i[1];
        int t = i[2];

        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    priority_queue<pr, vector<pr>, greater<pr>> q; // time, node
    q.push({0, 0});

    vector<int> dist(n, 1e9);
    dist[0] = 0;

    vector<int> ways(n, 0);
    ways[0] = 1;

    int mod = (int)(1e9 + 7);

    while (!q.empty())
    {
        auto top = q.top();
        int t = top.first;
        int node = top.second;
        q.pop();

        for (auto nbr : adj[node])
        {
            if (t + nbr.second < dist[nbr.first])
            {
                dist[nbr.first] = t + nbr.second;
                q.push({t + nbr.second, nbr.first});
                ways[nbr.first] = ways[node];
            }
            else if (t + nbr.second == dist[nbr.first])
            {
                ways[nbr.first] += ways[node];
            }
        }
    }

    return ways[n - 1] % mod;
}

int main()
{

    return 0;
}