#include <iostream>
#include <vector>
using namespace std;

bool DFS(int V, vector<int> adj[], vector<bool> &vis, vector<bool> &path, int node)
{
    vis[node] = true;
    path[node] = true;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            if (DFS(V, adj, vis, path, i) == true)
                return true;
        }

        else if (path[i])
            return true;
    }
    path[node] = false;

    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<bool> path(V, false);

    for (int i = 0; i < V; i++)
        if (!vis[i])
            if (DFS(V, adj, vis, path, i) == true)
                return true;
    return false;
}

int main()
{

    return 0;
}