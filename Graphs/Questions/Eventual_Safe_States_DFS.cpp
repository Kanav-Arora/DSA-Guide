// GFG: Eventual Safe States

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool DFS(int V, vector<int> adj[], vector<bool> &vis, vector<bool> &path, int node, vector<int> &ans)
{
    vis[node] = true;
    path[node] = true;

    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            if (DFS(V, adj, vis, path, i, ans) == true)
                return true;
        }
        else if (path[i])
            return true;
    }
    path[node] = false;

    ans.push_back(node);

    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<bool> path(V, false);

    vector<int> ans;
    for (int i = 0; i < V; i++)
        if (!vis[i])
            DFS(V, adj, vis, path, i, ans);
    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}