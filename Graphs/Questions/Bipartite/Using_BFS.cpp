#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool Check(int start, int V, vector<int> adj[], vector<int> &vis)
{
    queue<int> q;
    q.push(start);
    vis[start] = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (vis[i] == -1)
            {
                vis[i] = !vis[front];
                q.push(i);
            }
            else if (vis[i] == vis[front])
                return false;
        }
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
            val = val && Check(i, V, adj, vis);
    }

    return val;
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

    cout << isBipartite(vertices, v);
    return 0;
}

/*


*/