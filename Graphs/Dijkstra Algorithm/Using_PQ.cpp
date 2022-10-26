#include<iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include<climits>
#include <list>
#include <vector>

using namespace std;

typedef pair<int,int> pr;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> mp;        // adjacency list

    for (int i = 0; i < vec.size(); i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];

        mp[u].push_back({v, wt});
        mp[v].push_back({u, wt});
    }

    vector<int> dist(vertices, INT_MAX);
    priority_queue<pr, vector<pr>, greater<pr>> pq;

    dist[source] = 0;

    pq.push({0, source});

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int distance = p.first;
        int node = p.second;

        for (auto k : mp[node])
        {
            int visit = k.first;
            int wt = k.second;

            if (distance + wt < dist[visit])
            {
                dist[visit] = distance + wt;

                pq.push({dist[visit], visit});
            }
        }
    }

    return dist;
}

int main()
{

    return 0;
}