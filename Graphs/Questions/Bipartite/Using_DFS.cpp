#include <iostream>
#include <vector>
using namespace std;

bool Check(int node, int color, vector<int> adj[], vector<int> &vis)
{
    vis[node] = color;
    for (auto i : adj[node])
    {
        if (vis[i] == -1)
        {
            if (!Check(i, !color, adj, vis))
                return false;
        }
        else if (vis[i] == color)
            return false;
    }

    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> vis(V + 1, -1);
    bool val = true;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == -1)
            if (!Check(i, 0, adj, vis))
                return false;
    }

    return true;
}

int main()
{
    int vertices;
    cin >> vertices;
    int edges;
    cin >> edges;
    vector<int> v[vertices + 1];
    int v1, v2;
    while (edges--)
    {
        cin >> v1 >> v2;
        v[v1].push_back(v2);
    }

    cout << endl
         << "Graph Adjacency List created..." << endl;

    for (int i = 1; i <= vertices; i++)
    {
        cout << "[ " << i << " ]";

        for (int j = 0; j < v[i].size(); j++)
        {
            cout << " -> " << v[i][j];
        }

        cout << endl;
    }
    return 0;
}