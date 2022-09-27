#include <iostream>
#include <climits>
#include <vector>

using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wt = g[i].second;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int min_node;
        int min_val = INT_MAX;
        for (int k = 1; k <= n; k++)
        {
            if (mst[k] == false && key[k] < min_val)
            {
                min_val = key[k];
                min_node = k;
            }
        }

        mst[min_node] = true;

        for (auto k : adj[min_node])
        {
            int v = k.first;
            int wt = k.second;

            if (mst[v] == false && wt < key[v])
            {
                parent[v] = min_node;
                key[v] = wt;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

int main()
{

    return 0;
}