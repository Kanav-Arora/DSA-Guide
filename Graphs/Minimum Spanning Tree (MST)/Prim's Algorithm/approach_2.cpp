#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef pair<int, pair<int, int>> pr;
typedef pair<int, int> p;

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

    set<p> mst;
    priority_queue<pr, vector<pr>, greater<pr>> pq; // wt, node, parent
    vector<bool> vis(n, false);

    pq.push({0, {0, -1}});
    int sum = 0;

    while (!pq.empty())
    {
        auto front = pq.top();
        pq.pop();

        int wt = front.first;
        int node = front.second.first;
        int parent = front.second.second;

        if (vis[node])
            continue;

        vis[node] = true;
        mst.insert({parent, node});
        sum += wt;

        for (auto each : adj[node])
        {
            pq.push({each.second, {each.first, node}});
        }
    }
}

int main()
{

    return 0;
}