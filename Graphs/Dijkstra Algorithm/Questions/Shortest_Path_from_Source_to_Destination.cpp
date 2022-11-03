#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> dist(n + 1, {INT_MAX, -1});
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>, greater<pair<int, int>>>
        pq; // wt,node

    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    pq.push({0, 1});
    dist[1] = {0, -1};

    vector<int> ans;

    while (!pq.empty())
    {
        auto front = pq.top();
        pq.pop();

        int sum = front.first;
        int node = front.second;

        for (auto nbr : adj[node])
        {
            int n = nbr.first;
            int wt = nbr.second;

            if (sum + wt < dist[n].first)
            {
                dist[n].first = sum + wt;
                dist[n].second = node;

                pq.push({dist[n].first, n});
            }
        }
    }

    if (dist[n].first == INT_MAX)
        return {-1};

    ans.push_back(n);
    int curr = dist[n].second;
    while (curr != 1)
    {
        ans.push_back(curr);
        curr = dist[curr].second;
    }
    ans.push_back(1);

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}