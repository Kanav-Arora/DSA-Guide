#include <iostream>
using namespace std;

vector<pair<int, int>> adj[n];

for (int i = 0; i < flights.size(); i++)
{
    int u = flights[i][0];
    int v = flights[i][1];
    int cost = flights[i][2];

    adj[u].push_back({v, cost});
}

queue<pr> pq; // {stops, {node, dist}}
pq.push({0, {src, 0}});

vector<int> dist(n, 1e9);
dist[src] = 0;

while (!pq.empty())
{
    auto top = pq.front();
    int stops = top.first;
    int node = top.second.first;
    int d = top.second.second;
    pq.pop();

    if (stops > K + 1)
        continue;

    for (auto nbr : adj[node])
    {
        int n = nbr.first;
        int wt = nbr.second;

        if (d + wt < dist[n] && stops <= K)
        {
            dist[n] = d + wt;
            pq.push({stops + 1, {n, d + wt}});
        }
    }
}

return dist[dst] == 1e9 ? -1 : dist[dst];

int main()
{

    return 0;
}