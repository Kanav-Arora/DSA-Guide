/*
    Coding Ninjas:

    https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

*/


#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

void DFS(int node, int &timer, int parent, vector<int> &dis, vector<int> &low, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, vector<vector<int>> &result)
{
    vis[node] = true;
    dis[node] = low[node] = timer++;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
            continue;

        if (!vis[nbr])
        {
            DFS(nbr, timer, node, dis, low, vis, adj, result);

            // if I updated the nbr node in above call I need to update parent node

            low[node] = min(low[node], low[nbr]);

            // check bridge

            if (low[nbr] > dis[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
            // back edge
            low[node] = min(low[node], dis[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    int parent = -1;
    vector<int> dis(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> vis;
    vector<vector<int>> result;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            DFS(i, timer, parent, dis, low, vis, adj, result);
        }
    }

    return result;
}

int main()
{

    return 0;
}