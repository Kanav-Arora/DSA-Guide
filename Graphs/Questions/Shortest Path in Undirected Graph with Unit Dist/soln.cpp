// GFG Solution

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    vector<int> adj[N];

    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // create distance array

    vector<int> dist(N, 1e9);

    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto k : adj[front])
        {
            if (dist[front] + 1 < dist[k])
            {
                dist[k] = dist[front] + 1;
                q.push(k);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }

    return dist;
}

int main()
{

    return 0;
}